#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <deque>
#include <iomanip>
#include <cstdio>
#include <stack>
#include <numeric>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf 998244353
#define mod 998244353
#define rep(i,n) for(int i=0;i<(int)(n);++i)

ll ruijo(ll x,ll n){
	long long p,ans;
	if(n==0)return 1;
	if(n==1)return x;
	if(n%2){
		p = ruijo(x,n/2);
		ans = (x*p)%mod;
		ans = (ans*p)%mod;
		return ans;
	}else{
		p = ruijo(x,n/2);
		ans = (p*p)%mod;
		return ans;
	}
}

int main(){
    ll w,h;
    cin >> w >> h;
    cout << ruijo(2ll,w+h) << endl;

    return 0;
}