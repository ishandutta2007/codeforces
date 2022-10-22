#include <iostream>
#include <set>
using namespace std;

const int Maxn = 105;

int n, need[Maxn], fav[Maxn], group[Maxn];
int groupid;

void Search(int x)
{
     if (group[x]) return;
     group[x] = groupid;
     for (int i = 1; i <= n; i++)
        if (i + fav[i] == x || i - fav[i] == x ||
            x + fav[x] == i || x - fav[x] == i) Search(i);
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> need[i];
    for (int i = 1; i <= n; i++) cin >> fav[i];
    int i;
    for (i = 1; i <= n; i++) if (!group[i]) {
        groupid++;
        Search(i);
        set <int> S1, S2;
        for (int i = 1; i <= n; i++) if (group[i] == groupid) {
            S1.insert(i); S2.insert(need[i]);
        }
        if (S1 != S2) break;
    }
    if (i > n) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}