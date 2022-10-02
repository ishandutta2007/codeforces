#include <iostream>
#include <vector>
#include <map>

using namespace std;
#define x first
#define y second

vector<int> Prev, Next, S;
int M, N;

void update(int i, int x) {
    S[i+M] = x;
    i = (i+M)/2;
    while (i > 0) {
        S[i] = min(S[2*i],S[2*i+1]);
        i /= 2;
    }
}

int query(int i, int l, int r, int L, int R) {
    if (l >= R || r <= L) return N;
    if (l >= L && r <= R) return S[i];

    int m = (l+r)/2;
    return min(query(2*i, l, m, L, R), query(2*i+1, m, r, L, R));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> N;
    vector<int> A(N);
    Prev.resize(N);
    Next.resize(N);
    for (int &a:A) cin >> a;
    map<int, vector<int>> G;
    for (int i = 0; i < N; ++i) {
        G[A[i]].push_back(i);
    }

    M = 1;
    while (M < N) M *= 2;
    S.resize(2*M);
    fill(S.begin(),S.end(),N);

    for (auto&g:G) {
        int m = g.y.size();
        for (int i = 0; i < m; ++i) {
            Prev[g.y[i]] = i==0?-1:g.y[i-1];
            Next[g.y[i]] = i==m-1?N:g.y[i+1];
        }
    }

    for (int i = 0; i < N; ++i) S[M+i] = Next[i];
    for (int i = M-1; i > 0; --i) S[i] = min(S[2*i], S[2*i+1]);

    vector<int> Best(N, N);
    for (int i = 0; i < N; ++i) {
        if (Prev[i] != -1) {
            update(Prev[i], N);
            if (Prev[i] != i-1) {
                Best[Prev[i]] = query(1, 0, M, Prev[i]+1, i);
            }
        }
    }
    
    for (auto&g:G) {
        int m = g.y.size();
        for (int i = 0; i < m-3; ++i) {
            Best[g.y[i]] = min(Best[g.y[i]], g.y[i+3]); 
        }
    }
    

    vector<pair<int,int>> E(N+1, {0,0});
    for (int i = N-4; i >= 0; --i) {
        E[i] = {E[i+1].x, 0};
        if (Best[i] != N) {
            E[i] = max(E[i], {E[Best[i]+1].x + 1, 1}); 
        }
    }

    cout << 4 * E[0].x << endl;
    for (int i = 0; i < N; ++i) {
        if (E[i].y) {
            cout << A[i] << ' ' << A[Best[i]] << ' ' << A[i] << ' ' << A[Best[i]] << " \n"[E[i].x==1];
            i = Best[i];
        } 

    }
}