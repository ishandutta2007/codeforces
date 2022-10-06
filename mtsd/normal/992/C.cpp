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

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

ll mod = 1000000007;
long long calc(long long  k,ll m){
	if(m==0)return 1;
	if(m==1)return k%mod;
	long long s = calc(k,m/2);
	if(m%2==0){
		return (s*s)%mod;
	}else{
		long long ans;
		ans = (s*s)%mod;
		return (k*ans)%mod;
	}
}

int main(){
    ll x,k;
    cin >> x >> k; 
    if(x==0){
        cout << 0 << endl;
        return 0;
    }
    ll a = (calc((ll)2,k+1)*(x%mod))%mod;
    ll b = calc((ll)2,k);
    b = (b+mod-1)%mod;
    ll ans = (a+mod-b)%mod;
    cout << ans << endl;
    return 0;
}