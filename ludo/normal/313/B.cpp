#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define MAXN 100000

typedef long long ll;
typedef pair<int, int> pii;

string str;
int q[MAXN];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL

    cin >> str;
    q[0] = 0;
    for (unsigned int i = 1; i < str.size(); i++) {
        q[i] = q[i - 1] + (str[i] == str[i - 1]);
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        cout << (q[r - 1] - q[l - 1]) << endl;
    }

    return 0;
}