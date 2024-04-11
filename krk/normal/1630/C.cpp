#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;

int n;
int a[Maxn];
vector <int> V[Maxn];
vector <ii> seq;
int res;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        V[a[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++) if (!V[i].empty()) {
        if (V[i].size() > 2) res += int(V[i].size()) - 2;
        seq.push_back(ii(V[i][0], V[i].back()));
    }
    sort(seq.begin(), seq.end());
    int mx = -1;
    vector <ii> tmp;
    for (int i = 0; i < seq.size(); i++)
        if (seq[i].second < mx) res += 1 + int(seq[i].first != seq[i].second);
        else if (seq[i].first != seq[i].second) {
            tmp.push_back(seq[i]);
            mx = seq[i].second;
        }
    if (!tmp.empty()) {
        deque <ii> D; D.push_back(tmp[0]);
        for (int i = 1; i < tmp.size(); i++)
            while (true)
                if (tmp[i].first < D.front().second) {
                    if (D.size() >= 2) { res += 2; D.pop_back(); }
                    D.push_back(tmp[i]);
                    break;
                } else if (D.size() >= 2) { res++; D.pop_front(); }
                else {
                    D.pop_front();
                    D.push_back(tmp[i]);
                    break;
                }
        if (D.size() >= 2) res++;
    }
    printf("%d\n", res);
    return 0;
}