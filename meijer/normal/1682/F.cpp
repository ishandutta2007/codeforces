#include <bits/stdc++.h>
#define int long long
using namespace std;

#define fi first
#define se second
#define all(a) a.begin(), a.end()

const int N = (1<<20);

// mod library
typedef long long ll;
ll MOD=1e9+7;
 
inline ll mod(ll x_) {
    return (x_)%MOD;
}
ll modpow(ll x_, ll N_) {
    if(N_ == 0) return 1;
    ll a = modpow(x_,N_/2);
    a = (a*a)%MOD;
    if(N_%2) a = (a*x_)%MOD;
    return a;
}
ll inv(ll x_) {
    return modpow(x_, MOD-2);
}
class mi {
public:
    mi(ll v=0) {
        if (v > MOD) value = v % MOD;
        else if (v < 0) value = (MOD - (-v)%MOD)%MOD;
        else value = v;
    }
    mi  operator+ (ll rs) {return mod(value+rs);}
    mi  operator- (ll rs) {return mod(value-rs+MOD);}
    mi  operator* (ll rs) {return mod(value*rs);}
    mi  operator/ (ll rs) {return mod(value*inv(rs));}
    mi& operator+=(ll rs) {*this = (*this)+rs; return *this;}
    mi& operator-=(ll rs) {*this = (*this)-rs; return *this;}
    mi& operator*=(ll rs) {*this = (*this)*rs; return *this;}
    mi& operator/=(ll rs) {*this = (*this)/rs; return *this;}
    operator ll&() {return value;}
 
    ll value;
};
typedef vector<mi> vmi;

int n, q;
int a[N], b[N], l[N], r[N];
int sumb[N];
int sq[N], ans[N];

mi ft0[N];
void addft0(int i, mi x) {
    for (i++; i<N; i+=i&-i)
        ft0[i] += x;
}
mi getft0(int i) {
    mi res = 0;
    for (i++; i>0; i-=i&-i)
        res += ft0[i];
    return res;
}

mi ft1[N];
void addft1(int i, mi x) {
    for (i++; i<N; i+=i&-i)
        ft1[i] += x;
}
mi getft1(int i) {
    mi res = 0;
    for (i++; i>0; i-=i&-i)
        res += ft1[i];
    return res;
}

typedef array<int,4> i4;

signed main() {
    // input
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    for (int i=1; i<=n; i++)
        cin >> b[i];
    for (int i=0; i<q; i++)
        cin >> l[i] >> r[i];
    
    // fill sumb
    for (int i=1; i<=n; i++)
        sumb[i+1] = sumb[i] + b[i];
    
    // sort queries
    iota(sq,sq+q,0);
    sort(sq,sq+q,[](int i, int j) {return sumb[l[i]] < sumb[l[j]];});

    priority_queue<i4, vector<i4>, greater<i4>> pq;
    for (int i=1; i<=n; i++) {
        addft0(i, mi(-b[i])*mi(a[i]));
        pq.push({sumb[i]     , i, mi(-2)*mi(sumb[i])*mi(a[i]),  mi(2)*mi(a[i])});
        pq.push({sumb[i]+b[i], i, mi( 2)*mi(sumb[i])*mi(a[i]) + mi(2)*mi(b[i])*mi(a[i]), mi(-2)*mi(a[i])});
    }
    
    for (int i=0; i<q; i++) {
        int L = l[sq[i]];
        int R = r[sq[i]];
        int lsum = sumb[L];

        while (!pq.empty()) {
            i4 A = pq.top();
            if (A[0] <= lsum) {
                addft0(A[1], A[2]);
                addft1(A[1], A[3]);
                pq.pop();
            } else {
                break;
            }
        }

        ans[sq[i]] = getft0(R) - getft0(L-1) + (getft1(R) - getft1(L-1))*mi(lsum);
    }

    // output
    for (int i=0; i<q; i++)
        cout << ans[i] << endl;
}