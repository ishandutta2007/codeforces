#include <bits/stdc++.h>

using namespace std;

#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(n)-1;i>=(a);i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) (int)x.size()

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll>pll;
typedef vector<pii> vpii;

template<typename T>
T getint() {
    T x=0,p=1;
    char ch;
    do{ch=getchar();}while(ch <= ' ');
    if(ch=='-')p=-1,ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*p;
}

mt19937 gen(chrono::system_clock::now().time_since_epoch().count());

template<typename T1,typename T2>bool umin(T1 &x,const T2&y){if(x>y)return x=y,true;return false;}
template<typename T1,typename T2>bool umax(T1 &x,const T2&y){if(x<y)return x=y,true;return false;}

const int maxn=(int)4e5+10;
const int inf=(int)1e9+5;
const int mod=(int)1e9+7;
const ll llinf=(ll)1e18+5;
const ld pi=acos(-1.0);

int n, U;
int a[maxn];
ld t[maxn], b[maxn];

void build(int v, int l, int r) {
    if (l == r) return void(t[v] = b[l]);
    int tm = (l + r) / 2;
    build(v + v, l, tm);
    build(v + v + 1, tm + 1, r);
    t[v] = min(t[v + v], t[v + v + 1]);
}

ld getmin(int v, int l, int r, int tl, int tr) {
    if (l > r || tl > r || tr < l) return inf;
    if (l <= tl && tr <= r) return t[v];
    int tm = (tl + tr) / 2;
    return min(getmin(v + v, l, r, tl, tm), getmin(v + v + 1, l, r, tm + 1, tr));
}

bool can(ld x) {
    for(int i = 0; i < n - 1; ++i) {
        b[i] = (a[i + 1] - a[i] * x);
    }
    build(1, 0, n - 2);
    for(int k = 0; k < n; ++k) {
        int i = lower_bound(a, a + n, a[k] - U) - a;
        if (getmin(1, i, k - 2, 0, n - 2) <= a[k] * (1 - x)) return true;
    }
    return false;

}

int main() {
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);

    cin >> n >> U;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    if (!can(0)) cout << -1 << endl;
    else {
        ld lf = 0, rg = 1.05;
        while(rg - lf > 1e-10) {
            ld md = (lf + rg) / 2;
            if (can(md)) lf = md;
            else rg = md;
        }
        cout.precision(14);
        cout << rg << endl;
    }
    return 0;
}