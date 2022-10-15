#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const int stlckbmi=998244353,extlckbmi=1e9+7,altlckbmi=1e9;
const double lckbmi=32.9;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define actualrand(l,r) uniform_int_distribution<int>(l,r)(rng)
#define int long long
#define ff first
#define ss second
#define pii pair<int,int>
#define vi vector<int>
double euclid(int x1,int y1,int x2,int y2){
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int manhattan(int x1,int y1,int x2,int y2){
	return abs(x1-x2)+abs(y1-y2);
}
void solve(){
	//wch1207 and wch1234 so orz
	//i forgot how to read finnish
	int n;
	cin>>n;
	string s;
	cin>>s;
	int cnt=0;
	for(int i=0;i<n;i++){
		if(s[i]=='0')cnt++;
	}
	if(cnt&1&&!(cnt==1))puts("ALICE");
	else puts("BOB");
	return;
	//fuck im stupid
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T=1;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}