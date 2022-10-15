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
	//i will unintentionally or intentionally lose to elison because he will win div2 finals
	//havent warmed up
	//gonig to die
	//cant type
	//hioasgpoawuto8waugowgogiag
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			char dbsicorz;
			cin>>dbsicorz;
			if(dbsicorz=='.'){
				if((i+j)&1)cout<<"W";
				else cout<<"B";
			}
			else cout<<"-";
		}
		puts("");
	}
	return;
}
signed main(){
	int T=1;
	//cin>>T;
	while(T--){
		solve();
	}
	return 0;
}