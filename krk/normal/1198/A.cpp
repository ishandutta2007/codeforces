#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 400005;

int n, I;
map <int, int> M;
vector <ii> seq;
int sum[Maxn];

int main()
{
    scanf("%d %d", &n, &I); I *= 8;
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        M[a]++;
    }
    I /= n;
    int my = 1;
    for (int i = 0; i < I && my <= Maxn; i++)
        my *= 2;
    for (map <int, int>::iterator it = M.begin(); it != M.end(); it++)
        seq.push_back(*it);
    for (int i = 1; i <= seq.size(); i++)
        sum[i] = sum[i - 1] + seq[i - 1].second;
    int res = 0;
    if (seq.size() <= my) res = n;
    else for (int i = my; i <= seq.size(); i++)
            res = max(res, sum[i] - sum[i - my]);
    cout << n - res << endl;
    return 0;
}