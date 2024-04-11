#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300005;

int n, k;
int a[Maxn];
vector <int> seq;

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (i) seq.push_back(a[i] - a[i - 1]);
    }
    sort(seq.rbegin(), seq.rend());
    int res = 0;
    for (int i = k - 1; i < seq.size(); i++)
        res += seq[i];
    cout << res << endl;
    return 0;
}