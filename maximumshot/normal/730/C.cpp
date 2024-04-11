#include <bits/stdc++.h>
#define ALL(x) (x).begin(), (x).end()
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

const int inf = 1e9;
int const N = 5005;

vector<int> gr[N];
vector<pii> market[N]; // <price, cnt>
int depth[N];
int n, m, w;

void insert(map<ll, ll> &setik, pii m, ll &tot, ll &cnt, int &k) {
    setik[m.first] += m.second;
    tot += (ll)m.first * m.second;
    cnt += m.second;
    while ( cnt > k ) {
        pii end = *(--setik.end());
        int kv = min( (ll)end.second, (ll)cnt - k );
        tot -= kv * end.first;
        cnt -= kv;
        if ( kv == end.second ) {
            setik.erase( --setik.end() );
        } else {
            (--setik.end())->second -= kv;
        }
    }
}


int query() {
    int g, r, a;
    scanf("%d%d%d",&g,&a,&r);
    --g;
    for(int i = 0; i < n; ++i) {
        depth[i] = inf;
    }
    ll tot = 0, cnt = 0;
    depth[g] = 0;
    queue<int> q;
    map <ll, ll> setik;

    q.push(g);
    while ( !q.empty() ) {
        int v = q.front();
        q.pop();
        for( auto to : gr[v] ) {
            if ( depth[to] < inf ) continue;
            q.push( to );
            depth[to] = depth[v] + 1;
        }
        for(int i = 0; i < market[v].size(); ++i) {
            insert( setik, market[v][i], tot, cnt, a);
            if ( cnt >= a && tot <= r ) {
                return depth[v];
            }
        }
    }
    return -1;
}


int main() {
    scanf("%d%d",&n,&m);
    for(int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d%d",&a,&b);
        --a, --b;
        gr[a].push_back( b );
        gr[b].push_back( a );
    }
    scanf("%d",&w);
    for(int i = 0; i < w; ++i) {
        int c, k, p;
        scanf("%d%d%d",&c,&k,&p);
        c--;
        market[c].push_back( {p, k} );
    }
    for(int i = 0; i < n; ++i) {
        sort(ALL(market[i]));
    }
    int q;
    scanf("%d",&q);
    while(q--) {
        printf("%d\n", query());
    }


    return 0;
}