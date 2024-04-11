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
int it[1001][1001];
//int co[1001];
//int cur;
vector<int> adj[1001];
int st=0;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=0;i<n;i++){
			string s;
			cin>>s;
			for(int j=0;j<n;j++){
				if(j!=i){
					if(s[j]=='a'){
						it[i][j]=1;
					}
					else{
						it[i][j]=2;
					}
				}
			}
		}

		st=0;

		if(m%2==1){
			cout<<"YES"<<endl;
			for(int i=0;i<m+1;i++){
				if(i%2==0){
					cout<<1<<" ";
				}
				else{
					cout<<2<<" ";
				}
			}
			cout<<endl;
			continue;
		}
		pair<int,int> xx={-1,-1};
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(it[i][j]==it[j][i]){
					xx={i,j};
				}
			}
		}
		if(xx.a!=-1){
			cout<<"YES"<<endl;
			for(int i=0;i<m+1;i++){
				if(i%2==0){
					cout<<xx.a+1<<" ";
				}
				else{
					cout<<xx.b+1<<" ";
				}
			}
			cout<<endl;
			continue;
		}
		st=0;
		for(int i=0;i<n;i++){
			int aa=-1;
			int bb=-1;
			for(int j=0;j<n;j++){
				if(it[i][j]==1){
					aa=j;
				}
				else if(it[i][j]==2){
					bb=j;
				}
			}
			if(aa>-1 and bb>-1){
				st=1;
				cout<<"YES"<<endl;
				if(m%2==0){
					int xx=m;
					if(m%4==2){
						xx+=2;
					}
					vector<int> ans;
					ans.pb(i);
					for(int j=0;j<xx/4;j++){
						ans.pb(aa);
						ans.pb(i);
					}
					for(int j=0;j<xx/4;j++){
						ans.pb(bb);
						ans.pb(i);
					}
					if(m%4==0){
						for(auto j:ans){
							cout<<j+1<<" ";
						}
						cout<<endl;
					}
					else{
						for(int j=1;j+1<ans.size();j++){
							cout<<ans[j]+1<<" ";
						}
						cout<<endl;
					}
				}
				/*else{
					int xx=m;
					if(m%4!=1){
						xx=m+2;
					}
					vector<int> ans;
					ans.pb(aa);
					int kk=1;
					for(int j=0;j<xx/4;j++){
						ans.pb(bb);
						ans.pb(aa);
					}
					ans.pb(i);
					for(int j=0;j<xx/4;j++){
						if(it[aa][bb]==1){
							ans.pb(bb);
							ans.pb(i);
						}
						else{
							ans.pb(aa);
							ans.pb(i);
						}
					}
					if(xx!=m){
						for(int j=1;j+1<ans.size();j++){
							cout<<ans[j]+1<<" ";
						}
						cout<<endl;
					}
					else{
						for(auto j:ans){
							cout<<j+1<<" ";
						}
						cout<<endl;
					}
				}*/
				break;

			}

		}
		if(st==0){





			cout<<"NO"<<endl;
		}




	}











 
	return 0;
}