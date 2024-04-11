#include <bits/stdc++.h>
using namespace std;

int T;
int n;
map <int, int> M;

bool Check(int x)
{
    if (x > M.size()) return false;
    for (auto it: M)
        if (it.second >= x && int(M.size()) - int(it.second == x) >= x)
            return true;
    return false;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        M.clear();
        for (int i = 0; i < n; i++) {
            int a; scanf("%d", &a);
            M[a]++;
        }
        int lef = 0, rig = n;
        while (lef <= rig) {
            int mid = lef + rig >> 1;
            if (Check(mid)) lef = mid + 1;
            else rig = mid - 1;
        }
        printf("%d\n", rig);
    }
    return 0;
}