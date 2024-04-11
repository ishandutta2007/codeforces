//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(j==0){
					if(i%2==0){
						cout<<1;
					}
					else{
						cout<<0;
					}
				}
				else if(j==m-1){
					if(i%2==0){
						cout<<1;
					}
					else{
						cout<<0;
					}
				}
				else if(i==0){
					if(j>1 and j<m-2){
						if(j%2==0){
							cout<<1;
						}
						else{
							cout<<0;
						}
					}
					else{
						cout<<0;

					}
				}
				else if(i==n-1){
					if(j>1 and j<m-2){
						if(j%2==0){
							cout<<1;
						}
						else{
							cout<<0;
						}
					}
					else{
						cout<<0;
						
					}
				}
				else{
					cout<<0;
				}
			}
			cout<<endl;
		}
	}

 
 
 
 
 
 
 
	return 0;
}