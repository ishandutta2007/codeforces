//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo co[30];
llo it[200001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		for(llo j=0;j<30;j++){
			co[j]=0;
		}
		llo st=0;
		llo ma=0;
		for(llo i=0;i<n;i++){
			cin>>it[i];
			for(llo j=0;j<30;j++){
				if((1LL<<j)&it[i]){
					co[j]++;
					st=1;
					ma=max(ma,co[j]);
				}
			}
		}
		if(st==0){
			for(llo i=1;i<=n;i++){
				cout<<i<<" ";
			}
			cout<<endl;
		}
		else{
			for(llo j=0;j<30;j++){
				if(co[j]>0){
					ma=__gcd(ma,co[j]);
				}
			}
			for(llo i=1;i<=n;i++){
				if(ma%i==0){
					cout<<i<<" ";
				}
			}
			cout<<endl;
		}

	}
 
 
 

 
	return 0;
}