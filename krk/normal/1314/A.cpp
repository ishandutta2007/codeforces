#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 200005;

int n;
ii ai[Maxn];
ll cur;
ll res;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &ai[i].first);
    for (int i = 0; i < n; i++)
        scanf("%d", &ai[i].second);
    sort(ai, ai + n);
    priority_queue <int> Q;
    int A = 0, pnt = 0;
    while (pnt < n || !Q.empty())
        if (pnt < n && ai[pnt].first <= A) { Q.push(ai[pnt].second); cur += ai[pnt].second; pnt++; }
        else if (Q.empty()) A = ai[pnt].first;
        else {
            A++;
            cur -= Q.top(); Q.pop();
            res += cur;
        }
    cout << res << endl;
    return 0;
}