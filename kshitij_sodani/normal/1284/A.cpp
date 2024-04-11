//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
int n,m;
string s[21];
string t[21];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	for(int i=0;i<m;i++){
		cin>>t[i];
	}
	int q;
	cin>>q;
	while(q--){
		int y;
		cin>>y;
		cout<<s[(y-1)%n]<<t[(y-1)%m]<<endl;


	}





 
	return 0;
}