
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
		llo aa,bb,cc,dd;
		cin>>aa>>bb>>cc>>dd;
		llo ans=abs(aa-cc)+abs(bb-dd);
		if(aa!=cc and bb!=dd){
			ans+=2;
		}
		cout<<ans<<endl;
	}







	return 0;
}