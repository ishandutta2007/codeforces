#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const double eps = 1e-9;
const int oo = 0x3f3f3f3f;

pii read(vector<vector<string>> &A, int n, int m){
    pii x;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j){
            cin >> A[i][j];
            for (auto y : A[i][j])
                (y == '0' ? x.first : x.second)++;
        }

    return x;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<string>> A(n, vector<string>(m));
    vector<vector<string>> B(n, vector<string>(m));

    pii ta = read(A, n, m);
    pii tb = read(B, n, m);

    assert(ta == tb);

    vector<vi> mat(n, vi(m));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            mat[i][j] = A[i][j].size();

    vector<pii> Q, W;

    auto push = [&](int x0, int y0, int x1, int y1){
        assert(0 <= x0 && x0 < n && 0 <= y0 && y0 < m);
        assert(0 <= x1 && x1 < n && 0 <= y1 && y1 < m);

        assert(mat[x0][y0] > 0);

        Q.push_back({x0+1, y0+1});
        W.push_back({x1+1, y1+1});

        mat[x0][y0]--;
        mat[x1][y1]++;
    };

    // Phase 0
    // Move all 0 and 1 to first two rows

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j){
            reverse(A[i][j].begin(), A[i][j].end());

            for (auto x : A[i][j]){
                if (x == '0'){
                    if (i == 0)
                        push(i, j, i, (j + 1) % m);
                    else
                        push(i, j, 0, j);
                }
                else{
                    if (i == 1)
                        push(i, j, i, (j + 1) % m);
                    else
                        push(i, j, 1, j);
                }
            }
        }

    vector<vi> counts(2, vi(m));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j){
            int zeros = 0, ones = 0;
            for (auto x : B[i][j])
                (x == '0' ? zeros : ones)++;

            counts[0][(j + (i==0))%m] += zeros;
            counts[1][(j + (i==1))%m] += ones;
        }

    // Phase 1
    // Rebalancing values

    for (int u = 0; u <= 1; ++u){
        vector<int> A, B;
        for (int i = 0; i < m; ++i){
            if (mat[u][i] > counts[u][i])
                A.push_back(i);
            else
                B.push_back(i);
        }

        int p0 = 0, p1 = 0;

        while (true){
            while (p0 < (int)A.size() && mat[u][A[p0]] == counts[u][A[p0]])
                p0++;

            if (p0 == A.size()) break;

            while (p1 < (int)B.size() && mat[u][B[p1]] == counts[u][B[p1]])
                p1++;

            if (p1 == B.size()) break;

            while (mat[u][A[p0]] > counts[u][A[p0]] &&
                   mat[u][B[p1]] < counts[u][B[p1]])
                push(u, A[p0], u, B[p1]);
        }
    }

    // Phase 2
    // Assigning proper values to locations

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j){
            reverse(B[i][j].begin(), B[i][j].end());

            for (auto x : B[i][j]){
                if (x == '0'){
                    if (i == 0)
                        push(i, (j + 1) % m, i, j);
                    else
                        push(0, j, i, j);
                }
                else{
                    if (i == 1)
                        push(i, (j + 1) % m, i, j);
                    else
                        push(1, j, i, j);
                }
            }
        }

    cout << Q.size() << endl;
    for (int i = 0; i < (int)Q.size(); ++i)
        cout << Q[i].first << " " << Q[i].second << " " << W[i].first << " " << W[i].second << endl;
}