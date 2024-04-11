#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;

int n;
char s[Maxn], t[Maxn];
vector <int> ab, ba;
vector <ii> res;

int main()
{
    scanf("%d", &n);
    scanf("%s", s + 1);
    scanf("%s", t + 1);
    for (int i = 1; i <= n; i++)
        if (s[i] != t[i])
            if (s[i] == 'a') ab.push_back(i);
            else ba.push_back(i);
    if (int(ab.size() + ba.size()) % 2) {
        printf("-1\n"); return 0;
    }
    while (ba.size() >= 2) {
        res.push_back(ii(ba[int(ba.size()) - 2], ba[int(ba.size()) - 1]));
        ba.pop_back(); ba.pop_back();
    }
    while (ab.size() >= 2) {
        res.push_back(ii(ab[int(ab.size()) - 2], ab[int(ab.size()) - 1]));
        ab.pop_back(); ab.pop_back();
    }
    if (!ba.empty()) {
        res.push_back(ii(ba[0], ba[0]));
        res.push_back(ii(ba[0], ab[0]));
    }
    printf("%d\n", int(res.size()));
    for (int i = 0; i < res.size(); i++)
        printf("%d %d\n", res[i].first, res[i].second);
    return 0;
}