#include <bits/stdc++.h>
using namespace std;

typedef pair <int, string> is;

int n, m, k;
vector <is> V, res;

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m - 1; i++) {
        if (n > 1) {
            V.push_back(is(n - 1, "DRL"));
            V.push_back(is(n - 1, "U"));
        }
        V.push_back(is(1, "R"));
    }
    if (n > 1) {
        V.push_back(is(n - 1, "D"));
        V.push_back(is(n - 1, "U"));
    }
    if (m > 1) V.push_back(is(m - 1, "L"));
    for (int i = 0; i < V.size(); i++)
        if (V[i].first * int(V[i].second.size()) <= k) {
            res.push_back(V[i]);
            k -= V[i].first * int(V[i].second.size());
        } else {
            int hm = k / int(V[i].second.size());
            if (hm > 0) {
                res.push_back(is(hm, V[i].second));
                k -= hm * int(V[i].second.size());
            }
            if (k > 0) res.push_back(is(1, V[i].second.substr(0, k)));
            k = 0;
            break;
        }
    if (k > 0) printf("NO\n");
    else {
        printf("YES\n");
        printf("%d\n", int(res.size()));
        for (int i = 0; i < res.size(); i++)
            printf("%d %s\n", res[i].first, res[i].second.c_str());
    }
    return 0;
}