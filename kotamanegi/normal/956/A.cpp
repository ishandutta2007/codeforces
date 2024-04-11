#define  _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#pragma comment (linker, "/STACK:526000000")

#include "bits/stdc++.h"

using namespace std;
typedef string::const_iterator State;
#define eps 1e-11L
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL

#define MOD 998244353LL
#define seg_size 262144
#define pb push_back
#define mp make_pair
typedef long long ll;
#define REP(a,b) for(long long (a) = 0;(a) < (b);++(a))
#define ALL(x) (x).begin(),(x).end()

void init() {
    iostream::sync_with_stdio(false);
    cout << fixed << setprecision(20);
}


unsigned long xor128() {
    static unsigned long x = 123456789, y = 362436069, z = 521288629, w = 88675123;
    unsigned long t = (x ^ (x << 11));
    x = y; y = z; z = w;
    return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}


#define int long long
/*
int road[200][200];
int sea[200][200];

void solve(){
    while (true) {
        int n, m;
        cin >> n >> m;
        if (n == 0) return;
        REP(i, n) {
            REP(q, n) {
                road[i][q] = 1e9;
                sea[i][q] = 1e9;
            }
            road[i][i] = 0;
            sea[i][i] = 0;
        }
        REP(i, m) {
            int a, b, c;
            cin >> a >> b >> c;
            a--; b--;
            string d;
            cin >> d;
            if (d == "L") {
                road[a][b] = min(road[a][b], c);
                road[b][a] = min(road[b][a], c);
            }
            else {
                sea[a][b] = min(sea[a][b], c);
                sea[b][a] = min(sea[b][a], c);
            }
        }
        int query;
        cin >> query;
        vector<int> req;
        REP(i, query) {
            int a;
            cin >> a;
            a--;
            req.push_back(a);
        }
        vector<vector<int>> dist{ query,vector<int>(n,1e9) };
        dist[0][req[0]] = 0;
        for (int i = 0; i < query - 1; ++i) {
            REP(q, n) {
                dist[i + 1][q] = min(dist[i + 1][q], dist[i][q] + road[req[i]][req[i + 1]]);
            }
            vector<int> goi(n, 1e9);
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> next;
            REP(q, n) {
                goi[q] = dist[i][q];
                next.push(mp(dist[i][q], q));
            }
            while (next.empty() == false) {
                pair<int, int> now = next.top();
                next.pop();
                if (goi[now.second] != now.first) continue;
                REP(q, n) {
                    if (goi[q] > sea[now.second][q] + now.first) {
                        goi[q] = sea[now.second][q] + now.first;
                        next.push(mp(goi[q], q));
                    }
                }
            }
        }
    }
}
*/
void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> inputs;
    REP(i, n) {
        string a;
        cin >> a;
        inputs.push_back(a);
    }
    REP(i, n) {
        vector<int> yoko;
        vector<int> tate;
        REP(q, m) {
            if (inputs[i][q] == '.') continue;
            yoko.push_back(q);
        }
        if (yoko.empty() == true) continue;
        REP(q, n) {
            if (inputs[q][yoko[0]] == '#') {
                tate.push_back(q);
            }
        }
        REP(i, yoko.size()) {
            REP(q, n) {
                if (inputs[q][yoko[i]] == '#') {
                    int ok = 0;
                    REP(j, tate.size()) {
                        if (tate[j] == q) {
                            ok = 1;
                            break;
                        }
                    }
                    if (ok == 0) {
                        cout << "No" << endl;
                        return;
                    }
                }
            }
        }
        for (int q = 1; q < tate.size(); ++q) {
            REP(i, m) {
                if (inputs[tate[q]][i] == '#') {
                    int ok = 0;
                    REP(j, yoko.size()) {
                        if (yoko[j] == i) {
                            ok = 1;
                            break;
                        }
                    }
                    if (ok == 0) {
                        cout << "No" << endl;
                        return;
                    }
                }
            }
        }
        REP(i, yoko.size()) {
            REP(q, tate.size()) {
                if (inputs[tate[q]][yoko[i]] != '#') {
                    cout << "No" << endl;
                    return;
                }
                inputs[tate[q]][yoko[i]] = '.';
            }
        }
    }
    cout << "Yes" << endl;
}
#undef int
int main() {
    init();
    solve();
}