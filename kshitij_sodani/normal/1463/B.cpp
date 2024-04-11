//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'


llo it[51];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		llo su=0;
		llo su2=0;
		for(llo i=0;i<n;i++){
			cin>>it[i];
			if(i%2==0){
				su+=it[i];
			}
			else{
				su2+=it[i];
			}
		}
		if(su<su2){
			for(llo i=0;i<n;i++){
				if(i%2==0){
					cout<<1<<" ";
				}
				else{
					cout<<it[i]<<" ";
				}
			}
			cout<<endl;
		}
		else{
			for(llo i=0;i<n;i++){
				if(i%2==1){
					cout<<1<<" ";
				}
				else{
					cout<<it[i]<<" ";
				}
			}
			cout<<endl;
		}

	}







 
	return 0;
}