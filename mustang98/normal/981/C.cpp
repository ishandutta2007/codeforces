#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100111, inf = 1000111222;

vector<int> v[max_n];
int n;

int dfs(int a, int pr) {
    if (v[a].size() == 1) {
        return a;
    }
    if (v[a][0] == pr) {
        return dfs(v[a][1], a);
    }
    return dfs(v[a][0], a);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i + 1 < n; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        --a, --b;
        v[a].PB(b);
        v[b].PB(a);
    }
    int vmore2 = -1;
    for (int i = 0; i < n; ++i) {
        if (v[i].size() > 2) {
            if (vmore2 == -1) {
                vmore2 = i;
            } else {
                cout << "No";
                return 0;
            }
        }
    }
    if (vmore2 == -1) {
        vmore2 = 0;
    }
    cout << "Yes" << endl;
    cout << v[vmore2].size() << endl;
    vector<pair<int, int> > ans;
    for (int i = 0; i < v[vmore2].size(); ++i) {
        int to = v[vmore2][i];
        int fin = dfs(to, vmore2);
        printf("%d %d\n", vmore2 + 1, fin + 1);
    }

    return 0;
}