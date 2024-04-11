#include <bits/stdc++.h>
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
T gcd(T a,T b)
{
    if(a % b == 0){
        return b;
    }else{
        return gcd(b,a%b);
    }
}

template <typename T>
void extgcd(T a, T b, T& x, T& y)
{
    if(b != 0){
        extgcd(b,a%b,y,x);
        y -= (a/b)*x;
    }else{
        x = 1;
        y = 0;
    }
}

//mod  ll  (a * b % mod)
long long mod_prod(long long a, long long b, long long mod) {
    long long res = (a * b - (long long)((long double)a / mod * b) * mod) % mod;
    return res < 0 ? res + mod : res;
}

//mod10^6m1*x__int128( mod_prod )(10^12)
//(value, mod)
// template <typename T>
// pair<T, T> CRT(const pair<T, T>& a1, const pair<T, T>& a2)
// {
//     const T v1 = a1.first, m1 = a1.second;
//     const T v2 = a2.first, m2 = a2.second;
//     if(v1 == v2) return make_pair(v1,m1*m2);
//     T x, y;
//     extgcd(m1, m2, x, y);
//     x *= (v2 - v1), y *= (v2 - v1);
//     const T m = m1 * m2;
//     return make_pair((((m1 * x + v1) % m) + m) % m, m);
// }

//mod
//mod10^6m1*x__int128(10^12)
//(value, mod)
template <typename T>
pair<T, T> CRT(const pair<T, T>& a1, const pair<T, T>& a2)
{
    const T v1 = a1.first, m1 = a1.second;
    const T v2 = a2.first, m2 = a2.second;
    T g = gcd(m1, m2);
    T dev = (v2 - v1) / g;
    T mod = abs(v2 - v1) % g;
    if(mod) return make_pair(-1,-1);
    T x, y;
    extgcd(m1 / g, m2 / g, x, y);
    x *= dev, y *= dev;
    const T m = m1 / g * m2;
    return make_pair((((m1 * x + v1) % m) + m) % m, m);
}


ll A[2000000];
ll B[2000000];
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,m;
    ll k;
    cin >> n >> m >> k;
    vector<int> a(n);
    
    Fill(A,-1);
    Fill(B,-1);
    rep(i,n){
        cin >> a[i];
        A[a[i]] = i;
    }
    vector<int> b(m);
    rep(i,m){
        cin >> b[i];
        B[b[i]] = i;
    }
    vector<pair<ll,ll> > v;
    rep(i,1500000){
        if(A[i]!=-1&&B[i]!=-1){
            pair<ll,ll> x = MP(A[i],n);
            pair<ll,ll> y = MP(B[i],m);
            auto res = CRT(x,y);
            if(res.first!=-1){
                // cerr << A[i] << " " << n << " " << B[i] << " " << m << " " << res.first << " " << res.second << endl;
                v.push_back(res);
            }
        }
    }

    ll ok = -1;
    ll ng = (1LL<<62);
    while(ng-ok>1){
        ll mid = (ok+ng)/2;
        ll T = mid+1;
        for(auto &x:v){
            ll p = x.second;
            ll s = x.first;
            if(mid<s)continue;
            T -= (mid-s)/p + 1;
        }
        // cerr << mid << " " << T << endl;
        if(T>=k){
            ng = mid;
        }else{
            ok = mid;
        }
    }
    cout << ng + 1 << endl;
    return 0;
}