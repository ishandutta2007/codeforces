#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 505;

int n;
ii a[Maxn];

bool Check(int dist)
{
    int nd = 0;
    int rem = a[0].first - 1 + a[1].first - 1;
    for (int i = 1; i <= dist - 1; i++)
        if (a[n - i].first < 2) return false;
        else rem += a[n - i].first - 2;
    for (int i = dist; i <= n - 2; i++)
        if (rem == 0) return false;
        else rem += a[n - i].first - 2;
    return true;
}

void Solve(int dist)
{
    printf("YES %d\n", dist);
    printf("%d\n", n - 1);
    vector <ii> seq;
    seq.push_back(ii(a[0].first - 1, a[0].second));
    seq.push_back(ii(a[1].first - 1, a[1].second));
    int lst = a[0].second;
    for (int i = 1; i <= dist - 1; i++) {
        printf("%d %d\n", lst, a[n - i].second);
        lst = a[n - i].second;
        seq.push_back(ii(a[n - i].first - 2, a[n - i].second));
    }
    printf("%d %d\n", lst, a[1].second);
    for (int i = dist; i <= n - 2; i++) {
        int pnt = 0;
        while (seq[pnt].first == 0) pnt++;
        printf("%d %d\n", seq[pnt].second, a[n - i].second);
        seq[pnt].first--;
        seq.push_back(ii(a[n - i].first - 1, a[n - i].second));
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i].first);
        a[i].second = i + 1;
    }
    sort(a, a + n);
    for (int i = n - 1; i >= 1; i--)
        if (Check(i)) {
            Solve(i);
            return 0;
        }
    printf("NO\n");
    return 0;
}