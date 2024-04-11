#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Inf = 1000000000;
const int Maxn = 100005;

int n;
int mn[Maxn], mx[Maxn];
vector <ii> seq;
ll st, res;

int main()
{
    scanf("%d", &n);
    fill(mn, mn + Maxn, Inf);
    fill(mx, mx + Maxn, -Inf);
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        mn[a] = min(mn[a], i);
        mx[a] = max(mx[a], i);
    }
    for (int i = 0; i < Maxn; i++) if (mn[i] <= mx[i]) {
        seq.push_back(ii(mn[i], 1));
        seq.push_back(ii(mx[i], -1));
    }
    sort(seq.begin(), seq.end());
    for (int i = 0; i < seq.size(); i++)
        if (seq[i].second == 1) st++;
        else res += st;
    cout << res << endl;
    return 0;
}