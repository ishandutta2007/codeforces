#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'

int it[101][101];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=0;i<n;i++){
			string s;
			cin>>s;
			for(int j=0;j<m;j++){
				it[i][j]=s[j]-'0';
			}
		}
		if(it[0][0]==1){
			cout<<-1<<endl;
			continue;
		}
		vector<pair<pair<int,int>,pair<int,int>>> ans;
		for(int i=n-1;i>=0;i--){
			if(i>0){
				for(int j=0;j<m;j++){
					if(it[i][j]==0){
						ans.pb({{i,j},{i,j}});
					}
					else{
						ans.pb({{i-1,j},{i,j}});
					}
				}
			}
			else{
				for(int j=m-1;j>=1;j--){
					if(it[i][j]==0){
						ans.pb({{i,j},{i,j}});
					}
					else{
						ans.pb({{i,j-1},{i,j}});
					}
				}
			}
		}
		cout<<ans.size()<<endl;
		for(auto j:ans){
			cout<<j.a.a+1<<" "<<j.a.b+1<<" "<<j.b.a+1<<" "<<j.b.b+1<<endl;
		}
	}





	return 0;
}