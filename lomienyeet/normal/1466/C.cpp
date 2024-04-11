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
	//i still forgot how to read finnish
	//hanks pls have mercy
	//intense butterfly in stomach cus loser bracket
	string s;
	cin>>s;
	s="_"+s;
	int sum=0;
	for(int i=2;i<s.length();i++){
		if(s[i]==s[i-1]||s[i]==s[i-2]){
			sum++;
			s[i]='.';
		}
	}
	cout<<sum<<"\n";
	return;
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T=1;
	cin>>T;
	//comment the above line until i un-comment the above line
	while(T--){
		solve();
	}
	return 0;
}