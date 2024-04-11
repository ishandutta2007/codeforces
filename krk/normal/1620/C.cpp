#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
int n, k;
ll x;
string s;
vector <int> V;

void Solve(int ind, ll x)
{
    if (ind < 0) return;
    if (V[ind] == -1) {
        Solve(ind - 1, x);
        printf("a");
    } else {
        int wr = x % (V[ind] + 1);
        Solve(ind - 1, x / (V[ind] + 1));
        printf("%s", string(wr, 'b').c_str());
    }
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %I64d", &n, &k, &x); x--;
        cin >> s;
        V.clear();
        int cur = 0;
        for (int i = 0; i < n; i++)
            if (s[i] == 'a') {
                if (cur) {
                    V.push_back(cur);
                    cur = 0;
                }
                V.push_back(-1);
            } else cur += k;
        if (cur) V.push_back(cur);
        Solve(int(V.size()) - 1, x);
        printf("\n");
    }
    return 0;
}