//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
//typedef long long int;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
int it[501][501];
int dist[501][501];
int dist2[501][501];

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
				
				if(s[j]=='*'){
					it[i][j]=1;
				}
				else{
					it[i][j]=0;
				}
			}
		}
		for(int j=0;j<m;j++){
				for(int k=0;k<m;k++){
					dist[j][k]=0;
				}
			}
			
		int ans=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				for(int k=0;k<m;k++){
					dist2[j][k]=0;
				}
			}
			for(int j=0;j<m;j++){
				int st=1;
				for(int k=j;k<m;k+=1){
					dist2[j][k]=0;
					if(it[i][k]==0){
						st=0;
						break;
					}
					if((k-j)%2==0){
						if(j==k){
							ans+=1;
							dist2[j][k]=1;
						}
						else if(i>0){

							ans+=dist[j+1][k-1];

							if(dist[j+1][k-1]){
								dist2[j][k]=1;
							}
						}
					}
				}
			}
			for(int j=0;j<m;j++){
				for(int k=0;k<m;k++){
					dist[j][k]=dist2[j][k];
				}
			}
		}
		cout<<ans<<endl;




	}









 
	return 0;
}