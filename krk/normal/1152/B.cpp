#include <bits/stdc++.h>
using namespace std;

const int Maxb = 20;

int n;
vector <int> res;

int main()
{
    scanf("%d", &n);
    if (n % 2 == 0) {
        res.push_back(0);
        n++;
    }
    for (int i = Maxb - 1; i >= 0; i--)
        if (!(n & 1 << i)) {
            res.push_back(i + 1);
            n ^= ((1 << i + 1) - 1);
            n++;
        }
    printf("%d\n", int(res.size()) * 2);
    for (int i = 0; i < res.size(); i++)
        printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
    return 0;
}