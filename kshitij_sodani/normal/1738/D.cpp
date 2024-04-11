#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'

int bb[100001];
int pre[100001];
vector<int> kk[100001];
int ans[100001];
vector<int> adj[100001];
int co[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<=n;i++){
			pre[i]=0;
			kk[i].clear();
			co[i]=0;
			adj[i].clear();
		}
		vector<int> kk;
		int zz=0;
		for(int i=0;i<n;i++){
			cin>>bb[i];
			if(bb[i]==n+1){
				kk.pb(i+1);
				zz=0;
			}
			if(bb[i]==0){
				zz=1;
				kk.pb(i+1);
			}
			if(bb[i]>=1 and bb[i]<=n){
				adj[bb[i]].pb(i+1);		
			}
		}
		int ind=0;
		int ok=0;
		int ac=0;
		while(kk.size()){
			ok^=1;
			vector<pair<int,int>> mm;
			for(auto j:kk){
				//cout<<j<<":"<<adj[j].size()<<endl;
				mm.pb({adj[j].size(),j});
			}

			sort(mm.begin(),mm.end());
			
			kk.clear();
			for(int i=0;i<mm.size();i++){
				swap(mm[i].a,mm[i].b);
				ans[ind]=mm[i].a;

				ind++;
				for(auto j:adj[mm[i].a]){
					kk.pb(j);
				}
			}
			if(ok==1){
				ac+=mm.size();
			}
		}
		if(zz==0){
			cout<<ac<<endl;
		}
		else{
			cout<<n-ac<<endl;
		}
		
		for(int i=0;i<n;i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;

	}
	



	return 0;
}