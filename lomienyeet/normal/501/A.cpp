#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define ff first
#define ss second
#define pb push_back
#define multitest int T;cin>>T;while(T--)solve();
void solve(){
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	int maxi=max(3*a/10,a-a/250*c),mini=max(3*b/10,b-b/250*d);
	if(maxi<mini)cout<<"Vasya";
	else if(mini<maxi)cout<<"Misha";
	else cout<<"Tie\n";
}
int main(){
	//multitest
	solve();
	return 0;
}