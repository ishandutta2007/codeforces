#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 200;

int value[ maxn ][ maxn ];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int M = 600;
    vector<int> answer;

    int x = -1;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j){
            cin >> value[i][j];
            M = min(M, value[i][j]);
            if (value[i][j] == M)
                x = i;
        }

    
    if (n < m){
    for (int i = 0; i < M; ++i){
        for (int j = 1; j <= n; ++j)
            answer.push_back(j);
    }
    }
    else{
        for (int i = 0; i < M; ++i)
            for (int j = 1; j <= m; ++j)
                answer.push_back(-j);
    }

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            value[i][j] -= M;
  
    for (int i = 1; i <= m; ++i){
        if (value[x][i] == 0)
            continue;

        for (int j = 0; j < value[x][i]; ++j)
            answer.push_back(-i);

        int t = value[x][i];
        int k = 0;

        for (int j = 1; j <= n; ++j){
            value[j][i] -= t;
            k = min(k, value[j][i]);
        }

        if (k < 0){
            cout << -1 << endl;
            return 0;
        }
    }

    for (int i = 1; i <= n; ++i){
        for (int j = 0; j < value[i][1]; ++j)
            answer.push_back(i);

        for (int j = 1; j <= m; ++j){
            if (value[i][j] != value[i][1]){
                cout << -1 << endl;
                return 0;
            }
        }
    }

    cout << answer.size() << endl;
    for (auto u : answer)
        cout << (u < 0 ? "col" : "row") << " " << abs(u) << endl;

    return 0;
}