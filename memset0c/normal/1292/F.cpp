#include<bits/stdc++.h>
using namespace std;
const int N=65,mod=1e9+7;
int n,m,tot,sum,ans,in[N],out[N],anc[N],val[N],tag[N],fac[N],ifac[N],S[1<<15],dp[N][1<<15];
long long T[1<<15];
int find(int x){return anc[x]==x?x:anc[x]=find(anc[x]);}
inline int C(int n,int m){return n<m?0:(long long)fac[n]*ifac[m]%mod*ifac[n-m]%mod;}
int main(){
#ifdef memset0
	freopen("1.in","r",stdin);
#endif
	fac[0]=ifac[0]=ifac[1]=1;
	for(int i=2;i<N;i++)ifac[i]=(long long)(mod-mod/i)*ifac[mod%i]%mod;
	for(int i=1;i<N;i++)fac[i]=(long long)fac[i-1]*i%mod,ifac[i]=(long long)ifac[i-1]*ifac[i]%mod;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>val[i],tag[val[i]]=true;
	m=*std::max_element(val+1,val+n+1);
	for(int i=1;i<=m;i++)if(tag[i])anc[i]=i;
	for(int i=1;i<=m;i++)if(tag[i])
		for(int j=(i<<1);j<=m;j+=i)if(tag[j]){
			out[i]++,in[j]++;
			anc[find(i)]=find(j);
		}
	ans=1;
	// for(int i=1;i<=m;i++)printf("%d%c",tag[i]?find(i):-1," \n"[i==m]);
	for(int c=1;c<=m;c++)if(tag[c]&&find(c)==c){
		std::vector<int> a,b;
		std::vector<long long> A,B;
		for(int i=1;i<=m;i++)if(tag[i]&&find(i)==c){
			if(!in[i]){
				if(!out[i])continue;
				a.push_back(i);
			}else{
				b.push_back(i);
			}
		}
		if(!b.size())continue;
		A.resize(a.size());
		B.resize(b.size());
		for(int i=0;i<a.size();i++)
			for(int j=0;j<b.size();j++)
				if(b[j]%a[i]==0){
					A[i]|=1ll<<j;
					B[j]|=1ll<<i;
				}
		for(int x=0;x<(1<<a.size());x++){
			long long s=0,t=0;
			for(int i=0;i<a.size();i++)if((x>>i)&1)t|=A[i];
			for(int j=0;j<b.size();j++)if(((t>>j)&1)&&(x&B[j])==B[j])s|=1ll<<j;
			S[x]=__builtin_popcountll(s),T[x]=t;
		}
		sum=0;
		for(int i=0;i<b.size();i++){
			for(int i=0;i<=b.size();i++)memset(dp[i],0,(1<<a.size())<<2);
			dp[1][B[i]]=fac[S[B[i]]-1];
			for(int x=B[i],y;x<(1<<a.size());x++)
				for(int t=0;t<b.size();t++)if(((T[x]>>t)&1)&&(y=x|B[t])!=x)
					for(int i=1;i<b.size();i++)if(dp[i][x])
						for(int j=i+1;j<=b.size();j++){
							// printf("%d %d %d[%d] : %d(%d) -> %d(%d)\n",i,j,t,b[t],x,S[x],y,S[y]);
							dp[j][y]=(dp[j][y]+(long long)dp[i][x]*C(S[y]-j,S[y]-S[x]-1)%mod*fac[S[y]-S[x]-1])%mod;
						}
			for(int i=0;i<=b.size();i++)sum=(sum+dp[i][(1<<a.size())-1])%mod;
			// printf("%d[%d] %d\n",i,b[i],sum);
		}
		// for(int i=0;i<a.size();i++)printf("%d,%lld%c",a[i],A[i]," \n"[i+1==a.size()]);
		// for(int i=0;i<b.size();i++)printf("%d,%lld%c",b[i],B[i]," \n"[i+1==b.size()]);
		tot+=b.size()-1;
		ans=(long long)ans*sum%mod*C(tot,b.size()-1)%mod;
		// printf(">> %d %d\n",(int)b.size(),sum);
	}
	cout<<ans<<endl;
}