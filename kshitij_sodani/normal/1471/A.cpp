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
		llo aa=0;
		llo bb=0;
		llo n,x;
		cin>>n>>x;
		for(llo i=0;i<n;i++){
			llo cc;
			cin>>cc;
			aa+=cc;
			bb+=((cc+x-1)/x);
		}
		aa=(aa+x-1)/x;
		cout<<aa<<" "<<bb<<endl;
	}




 
	return 0;
}