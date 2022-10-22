
// Hallelujah, praise the one who set me free
// Hallelujah, death has lost its grip on me
// You have broken every chain, There's salvation in your name
// Jesus Christ, my living hope
#include <bits/stdc++.h> 
using namespace std;

#define REP(i, s, e) for (int i = (s); i < (e); i++)
#define RREP(i, s, e) for (int i = (s); i >= (e); i--)
template <class T>
inline bool mnto(T& a, T b) {return a > b ? a = b, 1 : 0;}
template <class T>
inline bool mxto(T& a, T b) {return a < b ? a = b, 1: 0;}
typedef long long ll;
typedef long double ld;
#define FI first
#define SE second
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> iii;
#define ALL(_a) _a.begin(), _a.end()
#define SZ(_a) (int) _a.size()
#define pb push_back
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<iii> viii;

#ifndef DEBUG
#define cerr if (0) cerr
#endif

const int INF = 1000000005;
const ll LINF = 1000000000000000005ll;
const int MAXN = 100005;
const int BLK = 8;

int n, w, q;
int x[MAXN];
ii k[MAXN];
iii p[MAXN];
ii fp[MAXN];
//int mn[MAXN][1 << BLK], mx[MAXN][1 << BLK];
int todo[(MAXN >> BLK) + 5];
int ans[MAXN];
priority_queue<ii, vii, greater<ii>> pq;
int pmn[(MAXN >> BLK) + 5][(1 << BLK) + 5],
    pmx[(MAXN >> BLK) + 5][(1 << BLK) + 5],
    smn[(MAXN >> BLK) + 5][(1 << BLK) + 5],
    smx[(MAXN >> BLK) + 5][(1 << BLK) + 5];

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> n >> w >> q;
    REP (i, 0, n) {
        cin >> x[i];
    }
    REP (i, 0, n) {
        int b = i >> BLK;
        if ((b << BLK) != i) {
            continue;
        }
        int obi = min(n, b + 1 << BLK);
        REP (j, 0, obi - i) {
            pmn[b][j] = x[i + j]; pmx[b][j] = x[i + j];
            if (j) {
                mnto(pmn[b][j], pmn[b][j - 1]);
                mxto(pmx[b][j], pmx[b][j - 1]);
            }
        }
        RREP (j, obi - i - 1, 0) {
            smn[b][j] = x[i + j]; smx[b][j] = x[i + j];
            if (j < obi - i - 1) {
                mnto(smn[b][j], smn[b][j + 1]);
                mxto(smx[b][j], smx[b][j + 1]);
            }
        }
    }
    REP (i, 0, n) {
        int b = i >> BLK;
        int bi = b << BLK, obi = min(n, b + 1 << BLK);
        p[i] = {i + 1, min(x[i], x[i + 1]), max(x[i], x[i + 1])};
        if (get<0>(p[i]) < obi) {
            pq.push({get<2>(p[i]) - get<1>(p[i]), i});
        }
        fp[i] = {obi - 1, obi - 1 - i};
        int cmn = x[i], cmx = x[i];
        REP (j, i + 1, obi) {
            mnto(cmn, x[j]); mxto(cmx, x[j]);
            //mn[i][j - bi] = cmn; mx[i][j - bi] = cmx;
        }
    }
    REP (i, 0, q) {
        cin >> k[i].FI;
        k[i].FI = w - k[i].FI;
        k[i].SE = i;
    }
    sort(k, k + q);
    int ep = 0;
    REP (z, 0, q) {
        auto [k, id] = ::k[z];
        cerr << k << '\n';
        while (!pq.empty() && pq.top().FI <= k) {
            auto [d, i] = pq.top(); pq.pop();
            int b = i >> BLK;
            int bi = b << BLK, obi = min(n, b + 1 << BLK);
            auto [cp, cmn, cmx] = p[i];
            cp++;
            mnto(cmn, x[cp]); mxto(cmx, x[cp]);
            p[i] = {cp, cmn, cmx};
            if (get<0>(p[i]) < obi) {
                pq.push({get<2>(p[i]) - get<1>(p[i]), i});
            }
            todo[b] = 1;
            cerr << ' ' << i << ' ' << get<0>(p[i]) << '\n';
        }
        REP (b, 0, ((n - 1) >> BLK) + 1) {
            if (!todo[b]) {
                continue;
            }
            todo[b] = 0;
            int s = b << BLK, e = min(n, b + 1 << BLK);
            RREP (i, e - 1, s) {
                if (get<0>(p[i]) == e) {
                    fp[i] = {i, 0};
                } else {
                    fp[i] = fp[get<0>(p[i])];
                    fp[i].SE++;
                }
                cerr << "  " << i << ' ' << fp[i].FI << ' ' << fp[i].SE << '\n';
            }
        }
        auto jump = [&] (int u) {
            int b = u >> BLK;
            int cmn = smn[b][u - (b << BLK)], cmx = smx[b][u - (b << BLK)];
            while (b <= ((n - 1) >> BLK)) {
                b++;
                int nmn = min(cmn, smn[b][0]), nmx = max(cmx, smx[b][0]);
                if (nmx - nmn > k) {
                    break;
                } else {
                    cmn = nmn; cmx = nmx;
                }
            }
            if (b > ((n - 1) >> BLK)) {
                return n;
            }
            int lo = b << BLK, hi = min(n, b + 1 << BLK) - 1, mid;
            while (lo < hi) {
                mid = lo + hi >> 1;
                int nmn = min(cmn, pmn[b][mid - (b << BLK)]),
                        nmx = max(cmx, pmx[b][mid - (b << BLK)]);
                if (nmx - nmn > k) {
                    hi = mid;
                } else {
                    lo = mid + 1;
                }
            }
            return hi;
        };
        ans[id] = fp[0].SE;
        int u = fp[0].FI;
        cerr << fp[0].FI << ' ' << fp[0].SE << '\n';
        while (u < n) {
            int v = jump(u);
            if (v == n) {
                break;
            }
            ans[id] += 1 + fp[v].SE;
            u = fp[v].FI;
        }
    }
    REP (i, 0, q) {
        cout << ans[i] << '\n';
    }
    return 0;
}