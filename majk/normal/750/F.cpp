#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

map<int, vector<int>> Memo;
int limit, res;

vector<int> query(int v) {
    if (Memo.find(v) != Memo.end()) return Memo[v];
    if (v == 1000 || res != -1) return {1000,1000,1000,1000};
    if (limit-- == 0) exit(0);

    cout << "? " << v << endl;
    int X; cin >> X;
    if (X == 0) exit(0);
    if (X == 2) res = v;
    vector<int> R(X);
    for(int&r:R) { cin >> r; if (r == 0) exit(0); }
    return Memo[v] = R;
}

bool hasLeaf(int u, int ig, int d) {
    auto R = query(u);
    if (R.size() == 1) return true;
    if (d == 0) return false;
    for(int r: R) if (r != ig) { return hasLeaf(r, u, d-1); }
}

int findDX(int n, int dXX, int dXXX) {
    vector<int> R = query(dXX);
    R.erase(remove(R.begin(),R.end(), dXXX), R.end());
    return R[hasLeaf(R[0], dXX, n-1)];
}

#define x first
#define y second

int solve(int H);

int main() {
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        Memo.clear();
        limit = 16;
        res = -1;

        int H; cin >> H;
        if (H == 0) return 0;
        cout << "! " << solve(H) << endl;
    }
}

int subsolve(int prev, int cur);

int solve(int H) {
        int beg = 1;
        vector<int> R = query(beg);
        if (R.size() == 2) return beg;

        vector<pair<int, vector<int>>> Q,S;
        for (int r: R) Q.push_back({r,{beg,r}});
        int d = 1;
        int rootd = -1;
        if (R.size() == 1) rootd = 0;
        if (H == 2) return R[0];
        while (rootd == -1 && res == -1) {
            for (auto q: Q) {
                R = query(q.x);
                if (R.size() == 2) {
                    return q.x;
                } else if (R.size() == 1) {
                    rootd = d;
                } else {
                    q.y.push_back(q.x);
                    for(int r: R) if (find(q.y.begin(),q.y.end(),r) == q.y.end()) { S.push_back({r,q.y}); break; }
                }
            } 

            Q.clear();
            swap(S,Q);
            ++d;
        }

        if (res != -1) return res;

        if (rootd == 0 && H == 3) {
            return subsolve(-1, beg);
        } else if (H == 3+rootd && H > 3) {
            for (int r: query(Q[0].y[1])) {
                if (H == 7) { if (r != beg && Q[0].y[2] != r) res = r; }
                else query(r);
            }
            return res;
        } else {
            int cur = rootd == 0 ? R[0] : Q[0].y[1];
            int prev = beg;
            while (rootd < H-4) {
                prev = findDX(++rootd, cur, prev); swap(cur, prev);
            }
            if (res != -1) return res;
            return subsolve(prev, cur);
        }
}

int subsolve(int prev, int cur) {
    for(int d2: query(cur)) 
        if (d2 != prev) 
            for(int d1: query(d2)) 
                if (d1 != cur) 
                    if (limit == 0 && res == -1) 
                        return d1; 
                    else 
                        query(d1);
    return res;
}