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
int it[301][301];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		int st=1;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>it[i][j];
				if(it[i][j]>4){
					st=0;
				}
				if((i==0 or i==n-1) and (j==0 or j==m-1)){
					if(it[i][j]>2){
						st=0;
					}
				}
				if(i==0 or j==0 or i==n-1 or j==m-1){
					if(it[i][j]>3){
						st=0;
					}
				}
			}
		}
		if(st==0){
			cout<<"NO"<<endl;
			continue;
		}
		cout<<"YES"<<endl;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if((i==0 or i==n-1) and (j==0 or j==m-1)){
					cout<<2<<" ";
					continue;
				}
				if(i==0 or j==0 or i==n-1 or j==m-1){
					cout<<3<<" ";
					continue;
				}
				cout<<4<<" ";
				continue;
			}
			cout<<endl;
		}
		
		
	}











 
	return 0;
}