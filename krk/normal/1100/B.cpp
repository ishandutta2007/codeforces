#include <bits/stdc++.h>
using namespace std;

int n, m;
map <int, int> M;

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a; scanf("%d", &a);
        M[a]++;
        if (M.size() >= n) {
            printf("1");
            map <int, int>::iterator it = M.begin();
            while (it != M.end())
                if (it->second > 1) { it->second--; it++; }
                else M.erase(it++);
        } else printf("0");
    }
    printf("\n");
    return 0;
}