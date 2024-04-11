#include<bits/stdc++.h>
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define lg2(x) __lg(x)
#define rem_dupl(x) sort(all(x)); x.erase(unique(all(x)), x.end())
using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int,int> ii;
#define x first
#define y second

//mt19937 rand32(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 rand64(chrono::steady_clock::now().time_since_epoch().count());

const db eps = 1e-9;
const int maxn = (int)3e5 + 5;
const ll mod = (int)1e9 + 7; // 998244353

int n, k;
ll a[maxn];

int dp[maxn], s[maxn];

bool ok(ll x){

    fill(dp, dp+n+1,0);
    dp[0] = 1;
    for(int i = 0; i < k; i++)
        s[i] = 1;

    int piv = 1;
    for(int i = k; i <= n; i++){
        while(a[i] - a[piv] > x)
            piv++;


        int x = s[i-k];
        if(piv-2 >= 0)
            x -= s[piv-2];

        if(piv - 1 <= i-k and x > 0)
            dp[i] = 1;

        s[i] = s[i-1] + dp[i];


        


    }

    return dp[n];

    

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);

    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    
    sort(a + 1, a + n + 1);

    ll l = 0, r = 1e9;
    while(l < r){
        ll mid = (l + r)>>1;
        if(ok(mid))
            r = mid;
        else 
            l = mid+1;
    }

    cout << l;
    
    
    return 0;
}