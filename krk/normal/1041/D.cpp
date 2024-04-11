#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;

int n, h;
int A[Maxn], B[Maxn];
int res;

int main()
{
    scanf("%d %d", &n, &h);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &A[i], &B[i]);
    res = h;
    int sumef = 0, sumget = 0;
    deque <ii> D;
    for (int i = n - 1; i >= 0; i--) {
        while (sumef >= h) {
            sumget -= D.front().first;
            sumef -= D.front().second;
            D.pop_front();
        }
        res = max(res, h + B[i] - A[i] + sumget);
        int myef = i > 0? A[i] - B[i - 1]: 0;
        sumef += myef; sumget += B[i] - A[i];
        D.push_back(ii(B[i] - A[i], myef));
    }
    printf("%d\n", res);
    return 0;
}