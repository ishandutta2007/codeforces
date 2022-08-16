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
	llo t;
	cin>>t;
	while(t--){
		llo n,aa,bb;
		cin>>n>>aa>>bb;
		llo cur=1;
		llo st=0;
		while(cur<=n){
			if((n-cur)%bb==0){
				st=1;
			}
			if(aa==1){
				break;
			}

			cur*=aa;
		}
		if(st){
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}

	}



	return 0;
}