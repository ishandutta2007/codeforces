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
	//oops
	int n;
	cin>>n;
	int arr[n+1],l[n+1],r[n+1],maxi,ptr;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		if(i==1){
			maxi=arr[i];
			l[ptr=1]=i;
		}
		else{
			if(maxi<arr[i]){
				l[++ptr]=i;
				r[ptr-1]=i-1;
				maxi=arr[i];
			}
		}
	}
	r[ptr]=n;
	for(int i=ptr;i>0;i--){
		for(int j=l[i];j<=r[i];j++)cout<<arr[j]<<" ";
	}
	puts("");
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