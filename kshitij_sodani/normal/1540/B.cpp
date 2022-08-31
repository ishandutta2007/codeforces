//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

llo n;
vector<llo> adj[201];
llo ss[201];
vector<llo> pp;
vector<llo> pp2;
const llo mod=1e9+7;


llo ee(llo aa,llo bb){
	if(bb==0){
		return 1;
	}
	llo ac=ee(aa,bb/2);
	ac=(ac*ac)%mod;
	if(bb%2==1){
		ac=(ac*aa)%mod;
	}
	return ac;
}
llo fac[200001];
llo fac2[200001];
llo cal(llo x,llo y){
 
	llo cur=(fac[x]*fac2[y])%mod;
	cur=(cur*fac2[x-y])%mod;
	return cur;
}


void dfs(llo no,llo par=-1,llo ii=-1){
	pp.pb(no);
	ss[no]=1;
	if(no==ii){
		pp2=pp;
	}
	for(auto j:adj[no]){
		if(j!=par){
			dfs(j,no,ii);
			ss[no]+=ss[j];
		}
	}
	pp.pop_back();

}
llo pre[200001];
llo pre2[200001];
llo dp[201][201];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	fac[0]=1;
	llo ma=200000;
	for(llo i=1;i<=ma;i++){
		fac[i]=(fac[i-1]*i)%mod;
		//cout<<fac[i]<<":";
	}
//	cout<<endl;
 
	for(llo i=ma;i>=0;i--){
		if(i==ma){
			fac2[i]=ee(fac[i],mod-2);
		}
		else{
			fac2[i]=(fac2[i+1]*(i+1))%mod;
		}
		//cout<<fac2[i]<<":";
	}
	llo n;
	cin>>n;

	pre[0]=1;
	for(int i=1;i<=n;i++){
		pre[i]=(pre[i-1]*2)%mod;

		//cout<<pre[i]<<"<";
	}
	//cout<<endl;

	pre2[0]=0;
	//cout<<pre[1]<<"/"<<endl;
	for(int i=1;i<=n;i++){
		pre2[i]=(pre2[i-1]+ee(pre[i],mod-2))%mod;
	}


	
	for(llo i=0;i<n-1;i++){
		llo aa,bb;
		cin>>aa>>bb;
		aa--;
		bb--;
		adj[aa].pb(bb);
		adj[bb].pb(aa);
	}
	llo ans=0;
	for(int i=1;i<=n;i++){
		dp[0][i]=1;
		dp[i][0]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dp[i][j]=(dp[i-1][j]+dp[i][j-1]);
			dp[i][j]*=((mod+1)/2);
			dp[i][j]%=mod;
		}
	}
	for(llo i=0;i<n;i++){
		for(llo j=0;j<i;j++){
			
			pp.clear();
			dfs(i,-1,j);
			/*if(i==2 and j==0){
				for(auto j:pp2){
						cout<<j<<"??";
					}
					cout<<endl;
			}*/
			pp=pp2;

			for(llo ii=0;ii+1<pp.size();ii++){
				llo x=ss[pp[ii]]-ss[pp[ii+1]];
				llo cur=x;//ee(n,mod-2);
				//cur=(cur*x)%mod;
				//cout<<cur<<"::"<<endl;
				if(ii==0){
					
					//cout<<i<<":"<<j<<":"<<x<<"/"<<n<<endl;
					ans=(ans+cur)%mod;
					continue;
				}
				llo xx=ii;
				llo yy=pp.size()-ii-1;
				cur=(cur*dp[xx][yy])%mod;
				//xx to xx+yy-1
				//cout<<i<<":"<<j<<":"<<x<<","<<xx<<":"<<yy<<endl;
				//cout<<((pre2[xx+yy-1]-pre2[xx-1]+mod)%mod)<<endl;
			//	cur*=(pre2[xx+yy-1]-pre2[xx-1]+mod);
				cur%=mod;
				ans=(ans+cur)%mod;
				continue;
				//swap(xx,yy);
			
				llo cur2=cal(xx+yy-1,xx-1)*ee(cal(xx+yy,xx),mod-2);
				cur2%=mod;
				//cur2=(1-cur2+mod)%mod;
				//cout<<cur2<<"::"<<endl;
				cur=(cur*cur2)%mod;
				ans=(ans+cur)%mod;

				
				
			}
		}
	}


		
	

		ans=(ans*ee(n,mod-2))%mod;
	cout<<ans<<endl;






	return 0;
}