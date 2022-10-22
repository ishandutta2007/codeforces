#include <bits/stdc++.h>
using namespace std;

const int Maxn = 2005;

int n;
vector <int> odd, ev;

int main()
{
    scanf("%d", &n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        sum += a;
        if (a % 2) odd.push_back(a);
        else ev.push_back(a);
    }
    sort(odd.rbegin(), odd.rend());
    sort(ev.rbegin(), ev.rend());
    int len = min(int(odd.size()), int(ev.size()));
    for (int i = 0; i < len; i++)
        sum -= (odd[i] + ev[i]);
    if (len < odd.size()) sum -= odd[len];
    if (len < ev.size()) sum -= ev[len];
    printf("%d\n", sum);
    return 0;
}