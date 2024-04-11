#include <iostream>
#include <set>
#include <vector>

using namespace std;

int N,A,B;
set<int> V,S,C,D;
bool solve(int u, bool&oa, bool &ob) {
    if (V.find(u) != V.end()) return true;
    V.insert(u);
    bool a = S.find(A-u) != S.end();
    bool b = S.find(B-u) != S.end();
    if (!a && !b) return false;
    if (a && !solve(A-u, oa, ob)) return false;
    if (b && !a) ob = true;
    if (b && !solve(B-u, oa, ob)) return false;
    if (a && !b) oa = true;
    return !oa || !ob;
}
void putA(int u) {
    if (C.find(u) == C.end()) {
        C.insert(u);
        putA(A-u);
        if (S.find(B-u) != S.end()) putA(B-u);
    }
}

int main() {
    cin >> N >> A >> B;
    vector<int> P(N); 
    for (int &p: P) cin >> p;
    for (int p: P) S.insert(p);
    for (int p: P) {
        bool oa = false, ob = false;
        if (V.find(p) == V.end()) {
            if (!solve(p, oa, ob)) {
                cout << "NO\n";
                return 0;
            }
            if (oa) putA(p); 
        }
    }


    cout << "YES\n";
    for (int i = 0; i < N; ++i) {
        cout << (C.find(P[i]) == C.end()) << " \n"[i==N-1];
    }

}