//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n'

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	if(n%2==1){
		cout<<0<<endl;
	}
	else{
		int ans=n/2;
		ans/=2;
		if(n%4==0){
			ans--;
		}
		cout<<ans<<endl;
	}




 
 
	return 0;
}