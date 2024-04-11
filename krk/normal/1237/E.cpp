#include <bits/stdc++.h>
using namespace std;

int n;
vector <int> seq;

void Gen(int lft, int val)
{
    if (lft == 0) return;
    Gen(lft - 1, 1 - val);
    seq.push_back(val);
    Gen(lft - 1, val);
}

int Solve(int lft, int val)
{
    seq.clear();
    Gen(lft, val);
    int add = 0;
    if (seq[0] != 1) add++;
    for (int i = 0; i + 1 < seq.size(); i++)
        if (seq[i] == seq[i + 1])
            if (i % 2 == 0) return 0;
            else add++;
    return int(seq.size()) + add == n;
}

int main()
{
    scanf("%d", &n);
    if (n == 1) { printf("1\n"); return 0; }
    int nd = 0;
    while (1 << nd <= n) nd++;
    nd--;
    printf("%d\n", Solve(nd, 0) + Solve(nd, 1));
    return 0;
}