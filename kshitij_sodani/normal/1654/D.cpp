#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'

const llo mod=998244353;
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

vector<pair<llo,pair<llo,llo>>> adj[200001];
llo vis[200001];
llo ma[200001];

llo vis3[200001];
llo su=0;
void dfs(llo no,llo par=-1,llo cur3=1){
	su=(su+cur3)%mod;
	for(auto j:adj[no]){
		if(j.a!=par){
			vector<llo> tt;
			llo cur=j.b.a;
			while(cur>1){
				vis[vis3[cur]]--;
				tt.pb(vis3[cur]);
				cur/=vis3[cur];
				
			}
			cur=j.b.b;
			while(cur>1){
				vis[vis3[cur]]++;
				tt.pb(vis3[cur]);
				cur/=vis3[cur];
				
			}
			for(auto j:tt){
				ma[j]=max(ma[j],vis[j]);
			}
			dfs(j.a,no,(((cur3*j.b.a)%mod)*ee(j.b.b,mod-2))%mod);
			cur=j.b.a;
			while(cur>1){
				vis[vis3[cur]]++;
				cur/=vis3[cur];
			}
			cur=j.b.b;
			while(cur>1){
				vis[vis3[cur]]--;
				cur/=vis3[cur];
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vis3[1]=0;
	for(llo i=2;i<=200000;i++){
		if(vis3[i]==0){
			vis3[i]=i;
			for(llo j=2*i;j<=200000;j+=i){
				if(vis3[j]==0){
					vis3[j]=i;
				}
			}
		}
	}
	llo t;
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		for(llo i=0;i<n;i++){
			adj[i].clear();
		}
		for(llo i=0;i<=n;i++){
			ma[i]=0;
			vis[i]=0;
		}
		for(llo i=0;i<n-1;i++){
			llo aa,bb,cc,dd;
			cin>>aa>>bb>>cc>>dd;
			aa--;
			bb--;
			llo ee=__gcd(cc,dd);
			cc/=ee;
			dd/=ee;
			adj[aa].pb({bb,{dd,cc}});
			adj[bb].pb({aa,{cc,dd}});
		}
		su=0;
		dfs(0);
		llo ans=1;
		for(llo i=1;i<=n;i++){
			if(ma[i]>0){
				ans=(ans*ee(i,ma[i]))%mod;
			}
		}
		ans=(ans*su)%mod;
		cout<<ans<<endl;
	}




	return 0;
}