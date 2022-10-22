#include <iostream>
#include <algorithm>
using namespace std;

const int Inf = 2000000000;
const int Maxn = 1005;

int n, m;
int q[Maxn];
int dh, in[Maxn];
int best[Maxn];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> q[i];
        best[i] = Inf;
    }
    dh = n;
    cin >> m;
    while (m--) {
          int a, b, c; cin >> a >> b >> c;
          if (in[b]++ == 0) dh--;
          best[b] = min(best[b], c);
    }
    if (dh > 1) cout << "-1\n";
    else {
         int sum = 0;
         for (int i = 1; i <= n; i++)
             if (in[i]) sum += best[i];
         cout << sum << endl;
    }
    return 0;
}