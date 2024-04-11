#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define vvi vector<vi>
#define ld long double
#define pi 3.14159265358979323846
#define eps 1e-9
#define pmin priority_queue<int,vector<int>,greater<int> >
#define pmax priority_queue<int>
#define foru(a,b) for(int i=a;i<b;i++)
#define ford(a,b) for(int i=a;i>=b;i--)
#define multitest int T;cin>>T;while(T--)solve();
#define mset(a,b) memset(a,b,sizeof(a))
inline void no(){
	cout<<"NO\n";
}
inline void yes(){
	cout<<"YES\n";
}
const int omg=1e9,mod=1e9+7;
void solve(){
	int a,b;
	cin>>a>>b;
	if(a==b)cout<<a<<"0 "<<b<<"1\n";
	else if(a+1==b)cout<<a<<"9 "<<b<<"0\n";
	else if(a==9&&b==1)cout<<a<<" "<<b<<"0\n";
	else puts("-1");
}
signed main(){
	//multitest
	solve();
	return 0;
}