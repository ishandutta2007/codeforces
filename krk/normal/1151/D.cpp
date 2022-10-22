#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 100005;

int n;
int a[Maxn], b[Maxn];
vector <ii> seq;
ll res;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &a[i], &b[i]);
        seq.push_back(ii(a[i] - b[i], i));
        res += ll(n) * b[i] - ll(a[i]);
    }
    sort(seq.rbegin(), seq.rend());
    for (int i = 0; i < seq.size(); i++)
        res += ll(seq[i].first) * (i + 1);
    cout << res << endl;
    return 0;
}