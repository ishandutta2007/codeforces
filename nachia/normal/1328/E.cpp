#include<bits/stdc++.h>
using namespace std;
using UL = unsigned long;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(int i = 0; i < (n); i++)

class Vector {
private:
    UL* mPointer;
    UL mSize;
    UL mReservedSize;

    void ReserveExact(UL size) {
        if (!size) {
            free(mPointer);
            mReservedSize = 0;
            return;
        }
        if (!mPointer) {
            void* tmp = malloc(sizeof(UL) * size);
            mPointer = (UL*)tmp;
            mReservedSize = size;
            return;
        }
        void* tmp = realloc(mPointer, sizeof(UL) * size);
        mPointer = (UL*)tmp;
        mReservedSize = size;
    }
    void ReserveWide(UL size) {
        if (size <= mReservedSize) return;
        if (!mPointer) return ReserveExact(size);
        return ReserveExact(max(mReservedSize << 1, size));
    }
public:
    Vector(UL sz = 0) :
        mPointer(nullptr),
        mSize(0),
        mReservedSize(0) { Resize(sz); }
    Vector(UL sz, UL v) :
        mPointer(nullptr),
        mSize(0),
        mReservedSize(0) {
        Resize(sz); rep(i, sz) mPointer[i] = v;
    }
    ~Vector() { free(mPointer); }
    UL Size() const { return mSize; }
    const UL& operator[](UL at) const { return mPointer[at]; }
    UL& operator[](UL at) { return mPointer[at]; }
    void Resize(UL newSize) { ReserveWide(newSize); mSize = newSize; }
    void Push(UL e) { Resize(Size() + 1); operator[](Size() - 1) = e; }
    void Pop(){ Resize(Size() - 1); }
    UL& Back() { return operator[](Size() - 1); }
    UL* begin() { return mPointer; }
    UL* end() { return mPointer + mSize; }
};

struct Problem {

    void Solve() {
        UL N, Q; scanf("%d%d", &N, &Q);
        vector<vector<UL>> E(N);
        rep(i, N - 1) {
            UL u, v; scanf("%d%d", &u, &v); u--; v--;
            E[u].push_back(v);
            E[v].push_back(u);
        }
        queue<UL> G; G.push(0);
        Vector D(N, -1); D[0] = 0;
        while (G.size()) {
            UL p = G.front(); G.pop();
            for (UL e : E[p]) {
                if (D[p] > D[e]) continue;
                G.push(e); D[e] = D[p] + 1;
            }
        }
        vector<Vector> Query(Q);
        vector<Vector> S(N);
        rep(i, Q) {
            UL k; scanf("%d", &k);
            Query[i].Resize(k);
            UL m = 0;
            rep(j, k) {
                scanf("%d", &Query[i][j]); Query[i][j]--;
                if (D[m] < D[Query[i][j]]) m = Query[i][j];
            }
            S[m].Push(i);
        }
        Vector V(N, 0);
        Vector H; H.Push(0);
        Vector ans(Q);
        while (H.Size()) {
            UL p = H.Back(); H.Pop();
            if (p < N) {
                V[p]++;
                for (UL e : E[p]) {
                    V[e]++;
                    if (D[p] > D[e]) continue;
                    H.Push(e + N);
                    H.Push(e);
                }
                for (UL query : S[p]) {
                    bool ok = true;
                    for (UL v : Query[query]) if (V[v] == 0) ok = false;
                    ans[query] = (ok ? 1 : 0);
                }
            }
            else {
                V[p - N]--;
                for (UL e : E[p - N]) V[e]--;
            }
        }
        rep(i, Q) printf(ans[i] ? "YES\n" : "NO\n");
    }
};

int main() {
    unique_ptr<Problem> p(new Problem());
    p->Solve();
    return 0;
}