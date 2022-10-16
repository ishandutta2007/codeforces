#include <bits/stdc++.h>

using namespace std;

const int MAXN = (int)1e5 + 10;

bool M[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b; cin >> a >> b;
    b--;
    M[0] = true;

    for (int i = 0; i <= b; ++i){
        int v; cin >> v;
        if (M[i]) M[i + v] = true;
    }

    if (M[b]) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}