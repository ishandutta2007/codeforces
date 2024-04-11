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

const int maxn=(int)1e5+10;
const int inf=(int)1e9+5;
const int mod=(int)1e9+7;
const ll llinf=(ll)1e18+5;
const ld pi=acos(-1.0);

ll v[maxn], t[maxn], add[maxn], extra[maxn];

ll sum(int l, int r) {
    return t[r] - t[l - 1];
}

int main() {
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> v[i];
    }
    for(int i = 1; i <= n; ++i) {
        cin >> t[i];
        t[i] += t[i - 1];
    }
    for(int i = 1; i <= n; ++i) {
        if (sum(i, n) <= v[i]) {
            add[i]++;
            continue;
        }
        if (v[i] <= t[i] - t[i - 1]) {
            extra[i] += v[i];
            continue;
        }
        int lf = i, rg = n;
        while(rg - lf > 1) {
            int md = (lf + rg) / 2;
            if (v[i] > sum(i, md)) lf = md;
            else rg = md;
        }
        add[i]++;
        add[rg]--;
        extra[rg] += v[i] - sum(i, rg - 1);
    }
    for(int i = 1; i <= n; ++i) {
        add[i] += add[i - 1];
    }
    for(int i = 1; i <= n; ++i) {
        cout << add[i] * 1LL * (t[i] - t[i - 1]) + extra[i] << ' ';
    }
    return 0;
}