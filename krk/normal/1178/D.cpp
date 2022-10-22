#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

int n;
vector <ii> res;

bool Prime(int x)
{
    if (x <= 1) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    for (int i = 3; i * i <= x; i += 2)
        if (x % i == 0) return false;
    return true;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int ni = (i + 1) % n;
        res.push_back(ii(i + 1, ni + 1));
    }
    for (int i = 4; !Prime(res.size()); i += 4) {
        if (!Prime(res.size())) res.push_back(ii(i - 3, i - 1));
        if (!Prime(res.size())) res.push_back(ii(i - 2, i));
    }
    printf("%d\n", int(res.size()));
    for (int i = 0; i < res.size(); i++)
        printf("%d %d\n", res[i].first, res[i].second);
    return 0;
}