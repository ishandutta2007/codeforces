//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo n,q;
vector<llo> adj[150001];
const llo cc=350;
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
llo co=0;
llo par2[150001];
llo st[150001];
llo endd[150001];
llo ss2[150001];
llo cop[150001];
void dfs(llo no,llo par=-1){
	st[no]=co;
	par2[no]=par;
	co++;
	for(auto j:adj[no]){
		if(j!=par){
			dfs(j,no);
		}
	}
	endd[no]=co-1;
	ss2[no]=endd[no]-st[no]+1;
}
vector<llo> tt;
vector<llo> xx;
llo vis[150001];
vector<int> kk[150001];
void dfs2(llo no,llo par=-1){
	for(auto j:tt){
		if(j==no){
			kk[no].pb(n);
			continue;
		}
		if(vis[j]==0){
			kk[no].pb(ss2[j]);
		}
		else{
			kk[no].pb(vis[j]);
		}
	}
	for(auto j:adj[no]){
		if(j!=par){
			if(adj[no].size()>=cc){
				vis[no]=n-ss2[j];
			}
			dfs2(j,no);
			if(adj[no].size()>=cc){
				vis[no]=0;
			}
		}
	}

}
llo tree[2000001];
void u(llo i,llo j){
//	return;
	while(i<=n){
		tree[i]+=j;
		if(tree[i]<0){
			tree[i]+=mod;
		}
		if(tree[i]>=mod){
			tree[i]-=mod;
		}
		i+=(i&-i);
	}
}
llo ss(llo i){
	llo su=0;
	while(i>0){
		su+=tree[i];
		i-=(i&-i);
		if(su>=mod){
			su-=mod;
		}
	}
	return su;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>q;
	for(llo i=0;i<n-1;i++){
		llo aa,bb;
		cin>>aa>>bb;
		aa--;
		bb--;
		adj[aa].pb(bb);
		adj[bb].pb(aa);
	}
	dfs(0);
	for(llo i=0;i<n;i++){
		if(adj[i].size()>=cc){
			tt.pb(i);
		}
	}
	dfs2(0);
	
	llo cur=0;
	/*for(llo i=0;i<n;i++){
		cout<<par2[i]<<":";
	}
	cout<<endl;
	return 0;*/
	while(q--){
		llo t;
		cin>>t;
		if(t==1){
			llo x,y;
			cin>>x>>y;
			//continue;
			
			x--;
			if(adj[x].size()<cc){
				cur=(cur+y)%mod;
				for(auto j:adj[x]){
					if(j!=par2[x]){
						llo xx=(y*(endd[j]-st[j]+1))%mod;
						cur=(cur+xx);//%mod;
						//u(1,xx);
						if(cur>=mod){
							cur-=mod;
						}
						//u(n+1,-xx);
						u(st[j]+1,-xx);
						u(endd[j]+2,xx);
					}
				}
				if(x!=0){
					llo xx=(y*(n-(endd[x]-st[x]+1)))%mod;
					u(st[x]+1,xx);
					u(endd[x]+2,-xx);
				}
			}
			else{
				cop[x]+=y;
				if(cop[x]>=mod){
					cop[x]-=mod;
				}
			}

		}
		else{
			llo x;
			cin>>x;
			x--;
		//	cout<<11<<endl;
		//	return 0;
			llo ans=ss(st[x]+1);
			ans=(ans+cur)%mod;
			for(llo i=0;i<tt.size();i++){
				ans=(ans+cop[tt[i]]*kk[x][i])%mod;
			}
			ans=(ans*ee(n,mod-2))%mod;
			
			cout<<ans<<endl;
		}
	}







 
	return 0;
}