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
		llo n;
		cin>>n;
		for(llo i=0;i<=3;i++){
			llo cur=n+i;
			llo xx=0;
			llo cur2=cur;
			while(cur){
				xx+=(cur%10);
				cur/=10;
			}
			if(__gcd(xx,cur2)>1){
				cout<<cur2<<endl;
				break;
			}
		}

	}







 
	return 0;
}