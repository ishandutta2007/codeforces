#include <bits/stdc++.h>
using namespace std;

template<typename T>
void sci(T& t) {
    cin >> t;
}

template<typename T, typename... Ts>
void sci(T& t, Ts&... ts) {
    sci(t);
    sci(ts...);
}

#define scid(vars...) int vars; sci(vars)
#define scidl(vars...) lint vars; sci(vars)
#define scidd(vars...) double vars; sci(vars)
#define scids(vars...) string vars; sci(vars)

template <typename T, typename Cmp=std::greater<int>>
using heap = priority_queue<T, std::vector<T>, Cmp>;

typedef long long lint;

int n;
vector<int> x[2];
bool used[7777][2];
bool lost[7777][2];
bool win[7777][2];
int deg[7777][2];

void dfs(int v, int w) {
    used[v][w] = true;
    for (int i : x[1 - w]) {
        int t = (v - i + n) % n;
        if (!used[t][1 - w]) {
            if (lost[v][w]) {
                win[t][1 - w] = true;
            } else if (--deg[t][1 - w] == 0) {
                lost[t][1 - w] = true;
            } else {
                continue;
            }
            dfs(t, 1 - w);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    sci(n);
    for (int i = 0; i < 2; i++) {
        scid(k);
        x[i].resize(k);
        for (int j = 0; j < k; ++j) {
            sci(x[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        deg[i][0] = x[0].size();
        deg[i][1] = x[1].size();
    }

    lost[0][0] = lost[0][1] = true;

    dfs(0, 0);
    if (!used[0][1]) {
        dfs(0, 1);
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 1; j < n; j++) {
            if (win[j][i]) {
                cout << "Win";
            } else if (lost[j][i]) {
                cout << "Lose";
            } else {
                cout << "Loop";
            }
            cout << " ";
        }
        cout << "\n";
    }




    return 0;
}