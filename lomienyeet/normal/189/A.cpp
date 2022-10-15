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
	int n,a,b,c;
	cin>>n>>a>>b>>c;
	int mx=0;
	for(int i=0;i*a<=n;i++){
		for(int j=0;i*a+b*j<=n;j++){
			if((n-a*i-b*j)%c==0&&((n-a*i-b*j)/c+i+j)>mx)mx=(n-a*i-b*j)/c+i+j;
		}
	}
	cout<<mx<<"\n";
}
signed main(){
	//multitest
	solve();
	return 0;
}