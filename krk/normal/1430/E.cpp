#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxl = 26;
const int Maxn = 200005;

int n;
char str[Maxn];
char rstr[Maxn];
vector <int> A[Maxl], B[Maxl];
int p[Maxn];
int BIT[Maxn];

void Add(int x)
{
    for (int i = x; i > 0; i -= i & -i)
        BIT[i]++;
}

int Get(int x)
{
    int res = 0;
    for (int i = x; i < Maxn; i += i & -i)
        res += BIT[i];
    return res;
}

int main()
{
    scanf("%d", &n);
    scanf("%s", str);
    for (int i = 0; i < n; i++)
        rstr[n - 1 - i] = str[i];
    for (int i = 0; i < n; i++) {
        A[str[i] - 'a'].push_back(i);
        B[rstr[i] - 'a'].push_back(i);
    }
    for (int i = 0; i < Maxl; i++)
        for (int j = 0; j < A[i].size(); j++)
            p[A[i][j]] = B[i][j];
    ll res = 0;
    for (int i = 0; i < n; i++) {
        res += Get(p[i] + 1);
        Add(p[i]);
    }
    cout << res << endl;
    return 0;
}