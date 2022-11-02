#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, pii> pp;
typedef long long ll;

const int N = 600 * 1000 + 10;
const int ADD = 300 * 1000 + 10;

map<pii, ll> ans;
set<pp> was;
int n;
int m;
int k;

set<pii> atsum[N];
set<pii> atdiff[N];

ll mabs(ll a) {
    return a > 0 ? a : -a;
}

ll dist(pii p1, pii p2) {
    return mabs(p1.first - p2.first);    
}

void model() {
    pii pos{0, 0};
    pii dir{1, 1};
    ll curTime = 0;
    for (;;) {
        //cerr << pos.first << " " << pos.second << " " << curTime << endl;
        //cerr << dir.first << " " << dir.second << endl;
        if (was.count(pp(pos, dir)))
            break;
        if (k == 0) {
            break;
        }
        was.insert(pp(pos, dir));
        int dx;
        int dy;
        if (dir.first > 0) {
            dx = n - pos.first; 
        } else {
            dx = pos.first;
        }              
        if (dir.second > 0) {
            dy = m - pos.second;
        } else {
            dy = pos.second;
        }
        int delta = min(dx, dy);
        pii next_pos{pos.first + delta * dir.first, pos.second + delta * dir.second};
        if (dir.first == dir.second) {
            int diff = pos.first - pos.second;
            for (pii xy : atdiff[diff + ADD]) {
                //cerr << xy.first << " " << xy.second << endl;
                ans[xy] = curTime + dist(xy, pos);
                atsum[xy.first + xy.second + ADD].erase(xy);
            }
            k -= atdiff[diff + ADD].size();
            atdiff[diff + ADD].clear();
        } else {
            int sum = pos.first + pos.second;
            for (pii xy : atsum[sum + ADD]) {
                ans[xy] = curTime + dist(xy, pos);
                atdiff[xy.first - xy.second + ADD].erase(xy);
            }
            k -= atsum[sum + ADD].size();
            atsum[sum + ADD].clear();
        }
        curTime += delta;
        pos = next_pos;
        if (dx < dy) {
            dir.first = -dir.first;
        } else if (dx > dy) {
            dir.second = -dir.second;
        } else {
            break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);    
    cin >> n >> m >> k;
    vector<int> x(k);   
    vector<int> y(k);
    for (int i = 0; i < x.size(); i++) {
        cin >> x[i] >> y[i];
        pii p{x[i], y[i]};
        atdiff[x[i] - y[i] + ADD].insert(p);
        atsum[x[i] + y[i] + ADD].insert(p);
        ans[p] = -1;
    }
    model();
    for (int i = 0; i < x.size(); i++) {
        cout << ans[pii(x[i], y[i])] << "\n";        
    }        
    return 0;
}