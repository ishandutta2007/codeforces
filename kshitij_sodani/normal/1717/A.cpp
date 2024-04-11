#include <bits/stdc++.h>
#define a first
#define b second
#define pb push_back
using namespace std;
#define endl '\n'
typedef long long llo;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		llo ans=0;
		ans+=n;
		ans+=2*(n/2);
		ans+=2*(n/3);
		cout<<ans<<endl;
	}






	return 0;
}