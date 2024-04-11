//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

int it[200001];
int vis[200001];
vector<int> pre[200001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;

		cin>>n;
		vector<int> ss;
		for(int i=0;i<=n;i++){
			vis[i]=0;
			pre[i].clear();
		}
		for(int i=0;i<n;i++){
			cin>>it[i];
			it[i]--;
			pre[it[i]].pb(i);
			vis[it[i]]=1;
		}
		for(int i=0;i<n;i++){
			if(vis[i]==0){
				ss.pb(i);
			}
		}
		int ans2=0;
		for(int i=0;i<n;i++){
			if(vis[i]==1){
				ans2++;
				if(pre[i].size()>1){
					map<int,int> tt;
					vector<int> ee;
					for(int j=0;j+1<pre[i].size();j++){
						ee.pb(ss.back());
						ss.pop_back();
					}
					ee.pb(i);
					for(auto j:ee){
						tt[j]=1;
					}
					map<int,int> ff;
					vector<int> ans;
					vector<int> ind;
					for(auto j:pre[i]){
						if(tt.find(j)!=tt.end()){
							ff[j]++;
							ans.pb(j);
						}
						else{
							ind.pb(ans.size());
							ans.pb(-1);
						}
					}

					for(auto j:tt){
						if(ff.find(j.a)==ff.end()){
							ans[ind.back()]=j.a;
							ind.pop_back();
						}
					}
					int xx=pre[i].size();
					for(int j=0;j<pre[i].size();j++){
						it[pre[i][j]]=ans[((j+1))%xx];
					}
					

				}
			}
		}
		
		cout<<ans2<<endl;
		for(int i=0;i<n;i++){
			cout<<it[i]+1<<" ";
		}
		cout<<endl;

	}

 
 
 
 
 
 
 
	return 0;
}