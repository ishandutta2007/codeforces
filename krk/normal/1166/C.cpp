#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
vector <int> pos, neg;
ll res;

int main()
{
    scanf("%d", &n);
    while (n--) {
        int a; scanf("%d", &a);
        pos.push_back(abs(a));
        /*if (a >= 0) pos.push_back(a);
        else neg.push_back(-a);*/
    }
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());
    for (int i = 0; i < neg.size(); i++)
        res += max(0, upper_bound(neg.begin(), neg.end(), 2 * neg[i]) - neg.begin() - i - 1);
    for (int i = 0; i < pos.size(); i++)
        res += max(0, upper_bound(pos.begin(), pos.end(), 2 * pos[i]) - pos.begin() - i - 1);
    cout << res << endl;
    return 0;
}