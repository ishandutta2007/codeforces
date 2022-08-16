//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

llo it[100001][6];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		for(llo i=0;i<n;i++){
			for(llo j=0;j<5;j++){
				cin>>it[i][j];
			}
		}
		llo cur=0;
		for(llo i=1;i<n;i++){
			llo su=0;
			for(llo j=0;j<5;j++){
				if(it[i][j]<it[cur][j]){
					su++;
				}
			}
			if(su>=3){
				cur=i;
			}
		}
		for(llo i=0;i<n;i++){
			if(i!=cur){
				llo su=0;
				for(llo j=0;j<5;j++){
					if(it[i][j]>it[cur][j]){
						su++;
					}
				}
				if(su<3){
					cur=-2;
					break;
				}
			}
		}
		cout<<cur+1<<endl;

	}
 
 

 
 
 
	return 0;
}