#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 105;

int T;
string str;
ii mx[Maxn];
vector <ii> res;

bool Solve()
{
    res.clear();
    int i = 0;
    while (i < str.length()) {
        ii best = ii(0, 0);
        int from;
        for (int j = 0; j <= i; j++) {
            if (mx[j] > best) {
                best = mx[j];
                from = j;
            }
        }
        if (best.first <= i) return false;
        res.push_back(ii(best.second, from));
        i = best.first;
    }
    return true;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        cin >> str;
        for (int i = 0; i < str.length(); i++)
            mx[i] = ii(0, 0);
        int n; scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            string sub; cin >> sub;
            for (int j = 0; j + sub.length() <= str.length(); j++)
                if (str.substr(j, sub.length()) == sub)
                    mx[j] = max(mx[j], ii(j + sub.length(), i));
        }
        if (Solve()) {
            printf("%d\n", int(res.size()));
            for (int i = 0; i < res.size(); i++)
                printf("%d %d\n", res[i].first, res[i].second + 1);
        } else printf("-1\n");
    }
    return 0;
}