#include <bits/stdc++.h>
using namespace std;

int T;
int n;
vector <int> res;

int main()
{
    scanf("%d", &T);
    while (T--) {
        res.clear();
        scanf("%d", &n);
        int b = 0;
        while ((1 << b + 1) < n) b++;
        for (int i = n - 1; i >= (1 << b); i--)
            res.push_back(i);
        res.push_back(0);
        for (int i = 1; i < (1 << b); i++)
            res.push_back(i);
        for (int i = 0; i < res.size(); i++)
            printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
    }
    return 0;
}