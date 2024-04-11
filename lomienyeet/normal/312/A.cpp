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
	/*omg wch pls bless me win some matches
	i will sacrifice 1226 firstborn free range cows from botswana every day
	split into 4 portions, botswana and hk time 00:26 and 12:26
	have mercy on me opponent
	DOUBLE YOU SEE ICH
	ONE TWO TWO SIX
	ORZZZZZZZZZZZZZZZZZZZZZZZZZ*/
	int n;
	cin>>n;
	string s;
	getline(cin,s);
	for(int i=0;i<n;i++){
		getline(cin,s);
		bool miao=0,lala=0;
		if(s.rfind("lala.")==s.size()-5)lala=1;
		if(s.find("miao.")==0)miao=1;
		if((miao&&lala)||(!miao&&!lala))puts("OMG>.< I don't know!");
		else if(lala)puts("Freda's");
		else puts("Rainbow's");
	}
	return;
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T=1;
	//cin>>T;
	while(T--){
		solve();
	}
	return 0;
}