#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second

const int MX=3e5;
ll t, n, s, l[MX], r[MX];
ll sumL;

bool possible(ll median) {
    priority_queue<ll> pq;
    RE(i,n) {
        if(r[i] >= median)
            pq.push(l[i]);
    }
    int needed=n/2 + 1;
    if(pq.size() >= needed) {
        ll added=0;
        RE(i,needed) {
            ll val = pq.top(); pq.pop();
            if(val < median)
                added += median-val;
        }
        return sumL+added <= s;
    } else {
        return 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--) {
        cin>>n>>s;
        RE(i,n) cin>>l[i]>>r[i];
        sumL = 0;
        RE(i,n) sumL+=l[i];
        ll lb=0, ub=s+1;
        while(lb != ub) {
            ll mid = (lb+ub+1)/2;
            if(possible(mid)) lb = mid;
            else              ub = mid-1;
        }
        cout<<lb<<endl;
    }
}