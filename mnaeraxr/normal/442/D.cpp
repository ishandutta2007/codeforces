#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int64> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 1000000 + 10;

int M1[maxn], W1[maxn];
int M2[maxn], W2[maxn];

int P[maxn];

bool update(int u, int value, int v){
    bool change = false;

    if (value > M1[u]){
        if (v == W1[u]){
            M1[u] = value;
            return true;
        }

        swap(value, M1[u]);
        swap(v, W1[u]);
        change = true;
    }

    if (value > M2[u] && v != W1[u]){
        swap(value, M2[u]);
        swap(v, W2[u]);
        change = true;
    }

    return change;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    for (int i = 2; i <= n + 1; ++i){
        cin >> P[i];

        int u = i;
        int dp = max(M1[i], M2[i] + 1);

        while (u > 1){
            int p = P[u];

            bool change = update(p, dp, u);

            if (!change) break;

            u = p;
            dp = max(M1[u], M2[u] + 1);
        }

        cout << M1[1] << " ";
    }

    cout << endl;

    return 0;
}
/*
11
1 2 2 2 3 6 3 3 8 1 6

20
1 2 2 2 3 6 3 3 8 1 6 7 7 9 9 15 10 13 6 1
Participant's output
1 1 2 2 2 2 2 2 2 2 3 3 3 3 3 3 3 3 3 3
Jury's answer
1 1 2 2 2 2 2 2 2 2 2 2 2 2 3 3 3 3 3 3
 */