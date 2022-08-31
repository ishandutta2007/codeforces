//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
int it[501][501];
vector<int> ss;
pair<int,int> par[501][501];
pair<int,int> find(pair<int,int> no){
	if(par[no.a][no.b].a==no.a and par[no.a][no.b].b==no.b){
		return par[no.a][no.b];
	}
	par[no.a][no.b]=find(par[no.a][no.b]);
	return par[no.a][no.b];
}
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
				par[i][j]={i,j};
				if(s[j]=='X'){
					it[i][j]=1;
				}
				else{
					it[i][j]=0;
				}
			}
		}
		if(n==1 or m==1){
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					cout<<'X';
				}
				cout<<endl;
			}
			continue;
		}

		for(int j=1;j<m;j+=3){
			for(int i=0;i<n;i++){
				it[i][j]=1;
			}
			if(j+1<m and j+2<m){
				int st=1;

				for(int i=0;i<n;i++){
					if(it[i][j+1]==1 or it[i][j+2]==1){
						st=0;
						it[i][j+1]=1;
						it[i][j+2]=1;
						if(j+2!=m-1){
							break;
						}
					}
				}
				if(st){
					it[0][j+1]=1;
					it[0][j+2]=1;
				}
			}
		}


	/*	for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(i==0){
					//it[i][j]=1;
					continue;
				}

				if(true){
					pair<int,int> xx=find({i-1,j});
					if(j<m-1){
						pair<int,int> yy=find({i,j+1});
						if(yy.a==xx.a and yy.b==xx.b){
							continue;
						}
					}
					if(j>0){
						pair<int,int> yy=find({i,j-1});
						if(yy.a==xx.a and yy.b==xx.b){
							continue;
						}
					}
					if(j>0 and j<m-1){
						pair<int,int> yy=find({i,j-1});
						pair<int,int> zz=find({i,j+1});
						if(yy.a==zz.a and yy.b==zz.b){
							continue;
						}
					}
					
				}
				it[i][j]=1;
				if(true){
					if(true){
						if(it[i-1][j]==1){
							pair<int,int> xx=find({i-1,j});
							par[xx.a][xx.b]={i,j};
						}
					}
					if(j<m-1){
						if(it[i][j+1]==1){
							pair<int,int> xx=find({i,j+1});
							par[xx.a][xx.b]={i,j};
						}
					}
					if(j>0){
						if(it[i][j-1]==1){
							pair<int,int> xx=find({i,j-1});
							par[xx.a][xx.b]={i,j};
						}
					}
				}
			}
		}*/

		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(it[i][j]){
					cout<<"X";
				}
				else{
					cout<<'.';
				}
			}
			cout<<endl;
		}

	}






 
	return 0;
}