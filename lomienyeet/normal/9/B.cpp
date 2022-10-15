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
	//As you know, students are a special sort of people, and minibuses usually do not hurry. That's why you should not be surprised, if Student's speed is higher than the speed of the minibus.
	int a,b,c,d,e,ptr=1;
	cin>>a>>b>>c;
	int arr[a+1];
	for(int i=1;i<=a;i++)cin>>arr[i];
	cin>>d>>e;
	double mini=1e18;
	for(int i=2;i<=a;i++){
		double cur=arr[i]*1.0/b+sqrt((d-arr[i])*(d-arr[i])+e*e)/c;
		if(cur<=mini){
			mini=cur;
			ptr=i;
		}
	}
	cout<<ptr<<"\n";
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