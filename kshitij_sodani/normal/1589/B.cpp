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
		int n,m;
		cin>>n>>m;
		cout<<((n*m)/3)+min(((n*m)%3),1)<<endl;
		continue;
		/*if(n%3==0){
			cout<<((n/3)*m)<<endl;
		}
		else if(m%3==0){
			cout<<((m/3)*n)<<endl;
		}
		else{
			cout<<((n*m)/3)+((1))
		}*/

	}



 
	return 0;
}