#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

const int Maxn = 100005;

int n;
vector <int> V[Maxn];

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x, y; cin >> x >> y;
        set <int> Divs;
        for (int j = 1; j * j <= x; j++)
           if (x % j == 0) {
                 Divs.insert(j);
                 Divs.insert(x / j);
           }
        int res = 0;
        for (set <int>::iterator it = Divs.begin(); it != Divs.end(); it++) {
            int pos = lower_bound(V[*it].begin(), V[*it].end(), i - y) - V[*it].begin();
            if (pos == V[*it].size()) res++;
            V[*it].push_back(i);
        }
        cout << res << endl;
    }
    return 0;
}