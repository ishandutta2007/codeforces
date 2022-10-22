#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <ll, ii> llii;

const int Maxn = 100005;
const ll Inf = 1000000000000000000ll;

int n, m;
int ax, ay, bx, by;
int X[Maxn], Y[Maxn];
vector <int> unX, unY;
vector <int> fromX[Maxn];
vector <int> fromY[Maxn];
priority_queue <llii> Q;
ll distX[Maxn], distY[Maxn];
ll res;

void Fix(vector <int> &V)
{
    sort(V.begin(), V.end());
    V.erase(unique(V.begin(), V.end()), V.end());
}

int main()
{
    scanf("%d %d", &n, &m);
    scanf("%d %d %d %d", &ax, &ay, &bx, &by);
    res = abs(ax - bx) + abs(ay - by);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &X[i], &Y[i]);
        unX.push_back(X[i]);
        unY.push_back(Y[i]);
    }
    Fix(unX);
    Fix(unY);
    for (int i = 0; i < m; i++) {
        X[i] = lower_bound(unX.begin(), unX.end(), X[i]) - unX.begin();
        Y[i] = lower_bound(unY.begin(), unY.end(), Y[i]) - unY.begin();
        fromX[X[i]].push_back(Y[i]);
        fromY[Y[i]].push_back(X[i]);
    }
    fill(distX, distX + int(unX.size()), Inf);
    fill(distY, distY + int(unY.size()), Inf);
    for (int i = 0; i < unX.size(); i++) {
        distX[i] = abs(unX[i] - ax);
        Q.push(llii(-distX[i], ii(i, 0)));
    }
    for (int i = 0; i < unY.size(); i++) {
        distY[i] = abs(unY[i] - ay);
        Q.push(llii(-distY[i], ii(i, 1)));
    }
    while (!Q.empty()) {
        ii v = Q.top().second;
        ll d = -Q.top().first; Q.pop();
        if (v.second == 0) {
            if (d != distX[v.first]) continue;
            if (v.first > 0) {
                ii u = ii(v.first - 1, 0);
                ll cand = d + unX[v.first] - unX[u.first];
                if (cand < distX[u.first]) {
                    distX[u.first] = cand;
                    Q.push(llii(-cand, u));
                }
            }
            if (v.first + 1 < unX.size()) {
                ii u = ii(v.first + 1, 0);
                ll cand = d + unX[u.first] - unX[v.first];
                if (cand < distX[u.first]) {
                    distX[u.first] = cand;
                    Q.push(llii(-cand, u));
                }
            }
            for (int i = 0; i < fromX[v.first].size(); i++) {
                ii u = ii(fromX[v.first][i], 1);
                res = min(res, d + ll(abs(unX[v.first] - bx)) + ll(abs(unY[u.first] - by)));
                ll cand = d;
                if (cand < distY[u.first]) {
                    distY[u.first] = cand;
                    Q.push(llii(-cand, u));
                }
            }
        } else {
            if (d != distY[v.first]) continue;
            if (v.first > 0) {
                ii u = ii(v.first - 1, 1);
                ll cand = d + unY[v.first] - unY[u.first];
                if (cand < distY[u.first]) {
                    distY[u.first] = cand;
                    Q.push(llii(-cand, u));
                }
            }
            if (v.first + 1 < unY.size()) {
                ii u = ii(v.first + 1, 1);
                ll cand = d + unY[u.first] - unY[v.first];
                if (cand < distY[u.first]) {
                    distY[u.first] = cand;
                    Q.push(llii(-cand, u));
                }
            }
            for (int i = 0; i < fromY[v.first].size(); i++) {
                ii u = ii(fromY[v.first][i], 0);
                res = min(res, d + ll(abs(unY[v.first] - by)) + ll(abs(unX[u.first] - bx)));
                ll cand = d;
                if (cand < distX[u.first]) {
                    distX[u.first] = cand;
                    Q.push(llii(-cand, u));
                }
            }
        }
    }
    cout << res << endl;
    return 0;
}