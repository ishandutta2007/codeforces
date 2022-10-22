#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
#define rep(i,n) For(i,0,(n)-1)
#define int long long
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N=5e3+10;
int n[15],k,a[15][N],sum,ss[15];
int g[1<<15],f[1<<15];
unordered_map<int,int> mp;
int pc[15],to[15],vis[15],tag,ban[15];
vector<int> tmp;
vector<int> sta[1<<15];
signed main(){
	k=read();rep(i,k)
		For(j,1,n[i]=read())sum+=a[i][j]=read(),ss[i]+=a[i][j];
	if(sum%k!=0)return puts("No"),0;
	sum/=k;int U=(1<<k)-1;
	rep(i,k)if(ss[i]==sum)U^=(1<<i),pc[i]=a[i][1],to[i]=i,ban[i]=1;else For(j,1,n[i])mp[a[i][j]]=i+1; 
	rep(i,k){
		For(j,1,n[i]){
			int del=sum-(ss[i]-a[i][j]);
			int pos=mp[del]-1,S=(1<<i);
			tag++,vis[i]=tag;int fl=0;tmp.clear(),tmp.push_back(i),tmp.push_back(pos);
			if(pos>i)while(1){
				S|=(1<<pos);vis[pos]=tag;
				del=sum-(ss[pos]-del);
				pos=mp[del];
				if(!pos||ban[pos-1])break;pos--;
				if(pos<i)break;
				if(del==a[i][j]){fl=1;break;}
				tmp.push_back(pos);
				if(vis[pos]==tag)break;
			}if(fl)g[S]=j,sta[S]=tmp;
		}
	}f[0]=1;For(S,1,(1<<k)-1)for(int T=S;T;T=(T-1)&S)if(g[T]&&(f[S^T]||!(S^T)))f[S]=T;
	if(!f[U])puts("No");
	else{
		puts("Yes");
		int S=U;
		while(S){
			int T=f[S];S^=T;
			int i=__builtin_ctz(T),j=g[T];
			int del=a[i][j];
			int len=sta[T].size();
			For(i,0,len-1){
				pc[sta[T][i]]=del,to[sta[T][i]]=sta[T][(i+len-1)%len],del=sum-(ss[sta[T][i]]-del);
			}
		}rep(i,k)printf("%lld %lld\n",pc[i],to[i]+1);
	}
	return 0;
}