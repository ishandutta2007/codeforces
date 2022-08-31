#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back
#define a first
#define b second
//#define endl '\n'
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		int it[n][m];
		int vis[n];
		int vis2[m];
		for(int i=0;i<n;i++){
			vis[i]=0;
		}
		for(int j=0;j<m;j++){
			vis2[j]=0;
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>it[i][j];
				if(it[i][j]){
					vis[i]=1;
					vis2[j]=1;
				}
			}
		}
		int co=0;
		int co2=0;
		for(int i=0;i<n;i++){
			if(vis[i]==0){
				co+=1;
			}
		}
		for(int i=0;i<m;i++){
			if(vis2[i]==0){
				co2+=1;
			}
		}
		int co3=min(co,co2);
		if(co3%2==1){
			cout<<"Ashish"<<endl;
		}
		else{
			cout<<"Vivek"<<endl;
		}


		


	}
	return 0;
}