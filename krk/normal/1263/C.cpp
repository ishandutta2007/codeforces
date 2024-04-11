#include <bits/stdc++.h>
using namespace std;

int t;
int n;
vector <int> V;

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        V.clear();
        int i = 1;
        while (i <= n) {
            int val = n / i;
            V.push_back(val);
            i = n / val + 1;
        }
        V.push_back(0);
        printf("%d\n", int(V.size()));
        for (int i = int(V.size()) - 1; i >= 0; i--)
            printf("%d%c", V[i], i - 1 >= 0? ' ': '\n');
    }
    return 0;
}