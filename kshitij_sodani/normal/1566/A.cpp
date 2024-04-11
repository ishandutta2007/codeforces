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
		int n,s;
		cin>>n>>s;
		int x=n-((n+1)/2)+1;
	//	cout<<s<<":"
		cout<<(s/x)<<endl;


	}


 
 
 
	return 0;
}