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

ll gcd(ll v,ll b){
	if(v>b) return gcd(b,v);
	if(v==b) return b;
	if(b%v==0) return v;
	return gcd(v,b%v);
}

vector<ll> dev;
vector<int> id;

void prime_factor(ll N){
	for(ll i=2;i*i<=N;i++){
		int cnt = 0;
		while(N%i == 0){
			cnt++;
			N /= i;
		}
		if(cnt){
			dev.push_back(i);
			id.push_back(cnt);
		}
	}
	if(N != 1){
		dev.push_back(N);
		id.push_back(1);
	}
	return;
}
template<typename T>
vector<T> divisor(T n)
{
    vector<T> res;
    for(T i=1;i*i<=n;i++){
        if(n%i==0){
            res.push_back(i);
            if(i != n/i){
                res.push_back(n/i);
            }
        }
    }
    sort(res.begin(),res.end());
    return res;
}


int main(){
    ll x,y,l,r;
    cin >> l >> r >> x >> y;
    if(y%x!=0){
        cout << 0 << endl;
        return 0;
    }
    ll z = y/x;
    vector<ll> v = divisor(z);
    int cnt = 0;
    for(int i=0;i<v.size();i++){
        ll a,b;
        a = v[i];
        b = z/v[i];
        a*=x;
        b*=x;
        if(a>=l&&a<=r&&b>=l&&b<=r&&gcd(a,b)==x){
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}