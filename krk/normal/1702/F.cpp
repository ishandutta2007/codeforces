#include <bits/stdc++.h>
using namespace std;

int T;
map <int, int> M;

bool Solve()
{
    while (!M.empty()) {
        auto it = M.end(); it--;
        int key = it->first, val = it->second; M.erase(it);
        if (val > 0) M[key / 2] += val;
        else if (val < 0)
                if (key % 2 == 0)
                    M[key / 2] += val;
                else return false;
    }
    return true;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        M.clear();
        int n; scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            int num; scanf("%d", &num);
            M[num]--;
        }
        for (int i = 0; i < n; i++) {
            int num; scanf("%d", &num);
            M[num]++;
        }
        printf("%s\n", Solve()? "YES": "NO");
    }
    return 0;
}