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
	//it is not recommended to randomly close your tab during match
	//need to lose to justin1 before the other match starts
	string s,t,p;
	cin>>s>>t>>p;
	int freq[26]={0};
	for(char c:p)freq[c-'a']++;
	int cnt=0,i;
	for(i=0;i<t.length();i++){
		if(s[i-cnt]!=t[i]){
			cnt++;
			if(freq[t[i]-'a'])freq[t[i]-'a']--;
			else break;
		}
	}
	if(i==t.length()&&s.length()+cnt==t.length())puts("YES");
	else puts("NO");
	return;
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