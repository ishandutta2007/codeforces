//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
int it[101][101];
int ee[101][101];

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
		vector<vector<int>> ans;
		for(int i=0;i<n-2;i++){
			for(int j=0;j<m;j++){
				if(it[i][j]==1){
					if(j<m-1){
						ans.pb({i,j,i+1,j,i+1,j+1});
					}
					else{
						ans.pb({i,j,i+1,j,i+1,j-1});
					}
					for(int ii=0;ii<ans.back().size();ii+=2){
						it[ans[ans.size()-1][ii]][ans[ans.size()-1][ii+1]]^=1;
					}
				}
			}
		}
		for(int j=0;j<m-2;j++){
			for(int i=n-2;i<n;i++){
				if(it[i][j]==1){
					ans.pb({i,j,n-2,j+1,n-1,j+1});
					for(int ii=0;ii<ans.back().size();ii+=2){
						it[ans[ans.size()-1][ii]][ans[ans.size()-1][ii+1]]^=1;
					}
				}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				ee[i][j]=it[i][j];
			}
		}
		vector<vector<int>> tt;
		vector<pair<int,int>> ss;
		for(int i=n-2;i<n;i++){
			for(int j=m-2;j<m;j++){
				ss.pb({i,j});
			}
		}
		for(int i=0;i<4;i++){
			vector<int> ee;
			for(int j=0;j<4;j++){
				if(i!=j){
					ee.pb(ss[j].a);
					ee.pb(ss[j].b);
				}
			}
			tt.pb(ee);
		}

		for(int ii=0;ii<(1<<4);ii++){
			for(int i=0;i<4;i++){
				if((1<<i)&ii){
					//cout<<i<<".";
					for(int j=0;j<tt[i].size();j+=2){
					//	cout<<tt[i][j]<<".."<<tt[i][j+1]<<"..";

						it[tt[i][j]][tt[i][j+1]]=it[tt[i][j]][tt[i][j+1]]^1;
					}
				}
			}
			int st=1;
			for(int i=n-2;i<n;i++){
				for(int j=m-2;j<m;j++){
					if(it[i][j]==1){
						st=0;
					}

				}
			}
			if(st==1){
				/*	for(int i=0;i<n;i++){
						for(int j=0;j<m;j++){
							cout<<it[i][j]<<"";
						}
						cout<<endl;
					}

					cout<<endl;*/
				/*if(st==1){

					cout<<ii<<endl;
				}*/
				for(int i=0;i<4;i++){
					if((1<<i)&ii){
						ans.pb(tt[i]);
					}
					
				}
			/*	for(int i=n-2;i<n;i++){
					for(int j=m-2;j<m;j++){
						it[i][j]=ee[i][j];
					}
				}*/

				break;
			}
			for(int i=n-2;i<n;i++){
				for(int j=m-2;j<m;j++){
					it[i][j]=ee[i][j];
				}
			}
		}
	/*	for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cout<<it[i][j];
			}
			cout<<endl;
		}*/
		cout<<ans.size()<<endl;
		for(auto j:ans){
			for(int i=0;i<j.size();i+=2){
				it[j[i]][j[i+1]]^=1;
			}
			for(auto k:j){
				cout<<k+1<<" ";
			}
			cout<<endl;
		}
		

	}




 
 
	return 0;
}