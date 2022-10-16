#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const double eps = 1e-9;
const int oo = 0x3f3f3f3f;

vector<pair<pii,pii>> solve(vector<pii> &P, int n){
    vector<vi> mat(n+1, vector<int>(n+1));
    int m = P.size();
    for (int i = 0; i < (int)P.size(); ++i)
        mat[P[i].first][P[i].second] = i + 1;

    vector<pair<pii,pii>> seq;
    function<void(int,int,int,int)> push = [&](int x, int y, int dx, int dy){
        int nx = x + dx, ny = y + dy;
        if (mat[nx][ny])
            push(nx, ny, dx, dy);
        mat[nx][ny] = mat[x][y];
        mat[x][y] = 0;
        seq.push_back({{x, y}, {nx, ny}});
    };

    int t = 1;

    for (int x = 1; x <= n; ++x){
        for (int y = 1; y <= n; ++y){
            if (mat[x][y])
            {
                int X = x, Y = y;
                if (X < t || y < t){
                    while (X < t){
                        push(X, Y, +1, 0);
                        X++;
                    }
                    while (Y < t){
                        push(X, Y, 0, +1);
                        Y++;
                    }
                }
                else{
                    while (X > t){
                        push(X, Y, -1, 0);
                        X--;
                    }
                    while (Y > t){
                        push(X, Y, 0, -1);
                        Y--;
                    }
                    t++;
                }
            }
        }
    }

    // cout << "Fase 2" << endl;

    for (int i = 1; i <= m; ++i){
        int x0 = i, y0 = i;
        int v = mat[i][i];

        while (y0 > v){
            push(x0, y0, 0, -1);
            y0--;
        }
        while (y0 < v){
            push(x0, y0, 0, +1);
            y0++;
        }
    }

    // cout << "Fase 3" << endl;

    for (int x = 1; x <= m; ++x){
        for (int y = 1; y <= m; ++y){
            if (mat[x][y]){
                int X = x;
                while (X > y){
                    push(X, y, -1, 0);
                    X--;
                }
                while (X < y){
                    push(X, y, +1, 0);
                    X++;
                }
            }
        }
    }

    for (int i = 1; i <= m; ++i)
        assert(mat[i][i] == i);

    return seq;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<pii> A(m), B(m);

    for (int i = 0; i < m; ++i){
        cin >> A[i].first >> A[i].second;
    }

    for (int i = 0; i < m; ++i){
        cin >> B[i].first >> B[i].second;
    }

    vector<pair<pii,pii>> seqa = solve(A, n);
    vector<pair<pii,pii>> seqb = solve(B, n);

    cout << seqa.size() + seqb.size() << endl;
    for (auto t : seqa){
        cout << t.first.first << " " << t.first.second << " ";
        cout << t.second.first << " " << t.second.second << endl;
    }
    reverse(seqb.begin(), seqb.end());
    for (auto t : seqb){
        cout << t.second.first << " " << t.second.second << " ";
        cout << t.first.first << " " << t.first.second << endl;
    }
}