#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
#define REP(a,b,c) for(ll a=ll(b); a<ll(c); a++)
#define RE(a,c) REP(a,0,c)
#define REV(a,b,c) for(ll a=ll(c-1); a>=ll(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second

const ll MX=1e5;
ll R, C;
ll r[MX], c[MX];
ll a[MX];

ll IDX(ll x, ll y) {
    return x+y*R;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>R>>C;
    RE(i,R) RE(j,C) cin>>a[IDX(i,j)];
    RE(i,R)
        RE(j,C)
            r[i] += a[IDX(i,j)], c[j] += a[IDX(i,j)];
    if(R <= 4 || C <= 4) {
        ll ans=0;
        RE(i,R) RE(j,C) ans += a[IDX(i,j)];
        cout<<ans<<endl;
        return 0;
    }

    ll ans=0;
    //4 rows
    {
        priority_queue<ll> q;
        RE(i,R) q.push(r[i]);
        ll tot=0;
        RE(i,4) tot+=q.top(), q.pop();
        ans = max(ans, tot);
    }
    //4 cols
    {
        priority_queue<ll> q;
        RE(i,C) q.push(c[i]);
        ll tot=0;
        RE(i,4) tot+=q.top(), q.pop();
        ans = max(ans, tot);
    }
    //2 rows 2 cols
    if(R < C) {
        RE(r1,R) REP(r2,r1+1,R) {
            priority_queue<ll> q;
            RE(i,C) q.push(c[i] - a[IDX(r1,i)] - a[IDX(r2,i)]);
            ll tot = r[r1] + r[r2];
            RE(i,2) tot += q.top(), q.pop();
            ans = max(ans, tot);
        }
    } else {
        RE(c1,C) REP(c2,c1+1,C) {
            priority_queue<ll> q;
            RE(i,C) q.push(r[i] - a[IDX(i,c1)] - a[IDX(i,c2)]);
            ll tot = c[c1] + c[c2];
            RE(i,2) tot += q.top(), q.pop();
            ans = max(ans, tot);
        }
    }
    //1 row 3 cols
    RE(r1,R) {
        priority_queue<ll> q;
        RE(i,C) q.push(c[i] - a[IDX(r1,i)]);
        ll tot = r[r1];
        RE(i,3) tot += q.top(), q.pop();
        ans = max(ans, tot);
    }
    //1 col 3 rows
    RE(c1,C) {
        priority_queue<ll> q;
        RE(i,C) q.push(r[i] - a[IDX(i,c1)]);
        ll tot = c[c1];
        RE(i,3) tot += q.top(), q.pop();
        ans = max(ans, tot);
    }
    cout<<ans<<endl;
}