#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 1005;

int n;
int R[Maxn];
int C[Maxn];
vector <ii> res1, res2;

int Get(int X[], int ind)
{
    int cur = ind;
    do cur = X[cur];
    while (cur > ind);
    return cur;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &R[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &C[i]);
    for (int i = 2; i <= n; i++) {
        ii got1 = ii(i, Get(C, i));
        ii got2 = ii(Get(R, i), i);
        if (got1 != got2) {
            res1.push_back(got1);
            res2.push_back(got2);
            swap(C[got1.second], C[i]);
            swap(R[got2.first], R[i]);
        }
    }
    printf("%d\n", int(res1.size()));
    for (int i = 0; i < res1.size(); i++)
        printf("%d %d %d %d\n", res1[i].first, res1[i].second, res2[i].first, res2[i].second);
    return 0;
}