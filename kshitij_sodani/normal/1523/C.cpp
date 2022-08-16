//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

int it[1001];
int vis[1001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>it[i];
			vis[i]=0;
		}
		vector<vector<int>> ans;
		for(int i=0;i<n;i++){
			if(i==0){
				cout<<1<<endl;
				ans.pb({1});
				continue;
			}
			if(it[i]==1){
				ans.pb(ans.back());
				ans[ans.size()-1].pb(1);
			}
			else{
				for(int j=i-1;j>=0;j--){
					if(vis[j]==0 and it[j]==it[i]-1){
						for(int k=j+1;k<i;k++){
							vis[k]=1;
						}
						vis[j]=1;
						ans.pb(ans[j]);

						ans[ans.size()-1][ans[ans.size()-1].size()-1]+=1;
						break;
					}

				}
			}
			vector<int> xx=ans.back();
			for(int j=0;j<xx.size();j++){
				cout<<xx[j];
				if(j+1<xx.size()){
					cout<<".";
				}
			}
			cout<<endl;
		}
	}








	return 0;
}