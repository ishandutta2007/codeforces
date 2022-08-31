//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

int t;
int it[300001];
int vis[1001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>it[i];
		}
		vector<int> ans;
		for(int i=0;i<n;i++){
			for(int j=0;j<=n;j++){
				vis[j]=0;
			}
			for(int j=0;j<n;j++){
				vis[it[j]]=1;
			}
			int ind=n;
			for(int j=0;j<=n;j++){
				if(vis[j]==0){
					ind=j;
					break;
				}
			}
			//cout<<ind<<":"<<endl;
			if(ind<n){
				ans.pb(ind+1);
				it[ind]=ind;
				continue;
			}
			int cc=-1;

			for(int j=0;j<n;j++){
				if(it[j]!=j){
					cc=j;
				}
			}
			if(cc==-1){
				break;
			}
			ans.pb(cc+1);
			it[cc]=n;
			if(true){
				int ind2=n;
				for(int j=0;j<=n;j++){
					vis[j]=0;
				}
				for(int j=0;j<n;j++){
					vis[it[j]]=1;
				}
				for(int j=0;j<=n;j++){
					if(vis[j]==0){
						ind2=j;
						break;
					}
				}
				ans.pb(ind2+1);
				it[ind2]=ind2;
			}



		}
		cout<<ans.size()<<endl;
		for(auto j:ans){
			cout<<j<<" ";
		}
		cout<<endl;
	}











 
	return 0;
}