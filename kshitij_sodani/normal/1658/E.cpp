#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'
int it[2001][2001];
pair<int,int> ind[2001*2001];
char ans[2001][2001];
int cur[3][3];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,k;
	cin>>n>>k;
	int m=n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>it[i][j];
			ind[it[i][j]]={i,j};
		}
	}
	for(int i=0;i<3;i+=2){
		for(int j=0;j<3;j+=2){
			cur[i][j]=-1e9;
		}
	}
	for(int ii=n*m;ii>=1;ii--){
		int st=1;
		for(int i=0;i<3;i+=2){
			for(int j=0;j<3;j+=2){
				if(cur[i][j]-(ind[ii].a*(i-1))-(ind[ii].b*(j-1))>k){
					st=0;

				}
			}
		}
		if(st==0){
			ans[ind[ii].a][ind[ii].b]='G';
		}
		else{
			ans[ind[ii].a][ind[ii].b]='M';
			for(int i=0;i<3;i+=2){
				for(int j=0;j<3;j+=2){
					cur[i][j]=max(cur[i][j],ind[ii].a*(i-1)+ind[ii].b*(j-1));
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<ans[i][j];
		}
		cout<<endl;
	}








	return 0;
}