//In the name of God
#include <bits/stdc++.h>
using namespace std; 

typedef long long ll; 
typedef long double ld;
typedef pair<int,int> pii; 
#define sz(x) ((int)(x).size())
#define X first
#define Y second

const int maxN = 1000 * 1000 + 10;
pair<pii, ll> a[maxN];

ll dp[maxN];

ld cross(int i, int j) { //when j passes i, i <= j
    ll up = dp[j] - dp[i];
    ll dn = a[j].X.X-a[i].X.X;
//    cerr << i << ' ' << j << ' ' << up << ' ' << dn << endl;
    assert(up >= 0);
    assert(dn > 0);
    return ld(up)/ld(dn);
}

int que[maxN], en, st; 

int main() { 
    ios::sync_with_stdio(false); cin.tie(0); 
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) 
        cin >> a[i].X.X >> a[i].X.Y >> a[i].Y;

    sort( a + 1, a + n + 1); 

    dp[0] = 0;
    que[en++] = 0;

    ll ans = 0;
    for(int i = 1; i <= n; i++) { 
        while( en - st > 1 && cross( que[st], que[st+1] ) >= a[i].X.Y )
            st++; 
        int u = que[st];
        dp[i] = dp[u] + ( a[i].X.X - a[u].X.X ) * 1ll * a[i].X.Y - a[i].Y;
        ans = max(ans, dp[i]);


        if( dp[i] >= dp[que[en-1]] ) {
            while( en - st > 1 && cross( que[en-2] , que[en-1] ) <= cross( que[en-2] , i ) )
                en--;
            que[en++] = i;
        }
    }

    cout << ans << endl;

    return 0;
}