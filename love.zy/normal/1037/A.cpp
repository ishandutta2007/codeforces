#include <bits/stdc++.h>
using namespace std;
#ifdef lizi
#include "local_debug.h"
#else
#define debug(...)
#endif
#define rep(i,a,n) for(int i=(a);i<(n);++i)
#define per(i,a,n) for(int i=(n)-1;i>=(a);--i)
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
#define puts(x) cout << (x) << '\n'
#define endl '\n'
#define scanf _______roundgodnb
#define printf _________roundgodgay
#define getchar ________roundgodlovecalabash
#define putchar ______________roundgod
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
constexpr db PI = acos(-1), eps = 1e-8;
constexpr ll mod = (ll)1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n;
    while (cin >> n) {
        int cnt=0;
        while(n) cnt++,n>>=1;
        cout<<cnt<<endl;
    }
    return 0;
}