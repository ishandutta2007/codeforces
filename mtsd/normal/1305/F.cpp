#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <iomanip>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cstdint>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define MP make_pair
#define PB push_back
#define inf 1000000007
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}
 
template<class T> inline bool chmax(T &a, T b){
    if(a<b){
        a = b;
        return true;
    }
    return false;
}

template<class T> inline bool chmin(T &a, T b){
    if(a>b){
        a = b;
        return true;
    }
    return false;
}
template<typename T>
T gcd(T a, T b)
{
    return b ? gcd(b, a % b) : a;
}

template<typename T>
T lcm(T a,T b)
{
    return  a / gcd(a,b) * b;
}



vector<long long> prime_factor(long long N){
    vector<long long> dev;
    for(int i=2;(long long)i*i<=N;i++){
		int cnt = 0;
		while(N%i == 0){
			cnt++;
			N /= i;
		}
		if(cnt){
			dev.push_back(i);
		}
	}
	if(N != 1){
		dev.push_back(N);
	}
	return dev;
}


ll a[200010];

int main(){
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    rep(i,n){
        cin >> a[i];
    }
    int sm2 = 0;
    int sm3 = 0;
    rep(i,n){
        if(a[i]%2!=0)sm2++;
        if(a[i]%3!=0){
            if(a[i]!=1){
                sm3++;
            }else{
                sm3 += 2;
            }
        }
    }
    ll mi = min(sm2,sm3);
    set<ll> st;
    rep(zz,30){
        ll p = a[rng()%n];
        ll q = a[rng()%n];
        for(int d = -1;d<=1;d++){
            for(int s = -1;s<=1;s++){
                ll pp = p+d;
                ll qq = q+s;
                if(pp<=0||qq<=0)continue;
                ll g = gcd(pp,qq);
                auto xx = prime_factor(g);
                for(auto x:xx){
                    if(st.count(x)==0){
                        ll tmp = 0;
                        rep(i,n){
                            ll K = a[i]%x;
                            if(a[i]<x){
                                tmp += x-K;
                            }else{
                                tmp += min(K,x-K);
                            }
                        }
                        if(tmp < mi){
                            mi = tmp;
                        }
                        st.insert(x);
                    }
                }
            }   
        }
    }
    cout << mi << endl;
    return 0;
}