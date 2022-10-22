#include<bits/stdc++.h>
#define STIZE(x) fprintf(stderr, "STIZE%d\n", x);
#define PRINT(x) fprintf(stderr, "%s = %d\n", #x, x);
#define NL(x) printf("%c", " \n"[(x)]);
#define lld long long
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
#define mid (l+r)/2
#define endl '\n'
#define all(a) begin(a),end(a)
#define sz(a) int((a).size())
#define LINF 1000000000000000LL
#define INF 1000000000
#define EPS 1e-9
using namespace std;
#define MAXN 100010
#define MAXB 5*MAXN
int N, K, x[MAXN], r[MAXN], q[MAXN], pret[MAXN], sled[MAXN], hshidx;
lld bit[MAXB], rez;
vector<int> iq[MAXN];
vector<pii> tr;
set<int> sQ, sX;
map<int,int> hQ, rhQ, hX;
priority_queue<pii, vector<pii>, greater<pii> > pq;
priority_queue<pii> pq1;
bool cmp(pii a, pii b) {
    return x[a.fi] < x[b.fi];
}
void update(int x, int val) {
    for(; x < MAXB; x+=x&-x) bit[x] += val;
}
lld query(int l, int r) {
    lld sum = 0;
    for(; r > 0; r-=r&-r) sum += bit[r];
    for(l--; l > 0; l-=l&-l) sum -= bit[l];
    return sum;
}
int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> N >> K;
    for(int i = 1; i <= N; i++) {
        cin >> x[i] >> r[i] >> q[i];
        sX.insert(x[i]);
        sX.insert(x[i]+r[i]);
        sX.insert(x[i]-r[i]);
        sQ.insert(q[i]);
    }
    hshidx = 0;
    for(auto x : sX) hX[x] = ++hshidx;
    hshidx = 0;
    for(auto q : sQ) hQ[q] = ++hshidx, rhQ[hshidx] = q;
    for(int i = 1; i <= N; i++) {
        iq[hQ[q[i]]].pb(i);
        pret[i] = hX[x[i]-r[i]];
        sled[i] = hX[x[i]+r[i]];
        x[i] = hX[x[i]];
    }
    for(int i = 1; i <= sz(sQ); i++) {
        for(int j = i; j <= sz(sQ) && rhQ[j] <= rhQ[i]+K; j++) {
            for(auto x : iq[j]) tr.pb({x, (i==j)});
        }
        sort(all(tr), cmp);
        for(auto cur : tr) {
            int idx = cur.fi;
            if(cur.se) {
                while(!pq.empty() && pq.top().fi < x[idx]) update(pq.top().se, -1), pq.pop();
                rez += query(pret[idx], x[idx]);
            }
            update(x[idx], 1);
            pq.push({sled[idx], x[idx]});
        }
        while(!pq.empty()) update(pq.top().se, -1), pq.pop();
        for(int k = sz(tr)-1; k >= 0; k--) {
            pii cur = tr[k];
            int idx = cur.fi;
            if(cur.se) {
                while(!pq1.empty() && pq1.top().fi > x[idx]) update(pq1.top().se, -1), pq1.pop();
                rez += query(x[idx], sled[idx]);
            } else {
                update(x[idx], 1);
                pq1.push({pret[idx], x[idx]});
            }
        }
        while(!pq1.empty()) update(pq1.top().se, -1), pq1.pop();
        tr.clear();
    }
    cout << rez;
    return 0;
}