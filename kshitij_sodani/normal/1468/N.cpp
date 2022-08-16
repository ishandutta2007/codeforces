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
		int aa,bb,cc;
		cin>>aa>>bb>>cc;
		int dd,ee,ff,gg,hh,ii;
		cin>>dd>>ee>>ff>>gg>>hh;
		aa-=dd;
		bb-=ee;
		cc-=ff;
		//
		if(aa<0 or bb<0 or cc<0){
			cout<<"NO"<<endl;
		}
		else{
			gg-=min(gg,aa);

			hh-=min(hh,bb);
			if(gg+hh<=cc){
				cout<<"YES"<<endl;
			}
			else{
				cout<<"NO"<<endl;
			}


		}

	}


 
	return 0;
}