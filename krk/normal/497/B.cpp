#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;

int n;
vector <int> A, B;
vector <ii> res;

int Get(const vector <int> &V, int ind, int t)
{
    if (ind + t > V.size()) return Maxn;
    return V[ind + t - 1] + 1;
}

bool getS(int t, int &s)
{
    s = 0;
    int ma = 0, mb = 0;
    int lst = 0;
    int i = 0, j = 0;
    while (i < A.size() || j < B.size()) {
        int mn1 = Get(A, i, t);
        int mn2 = Get(B, j, t);
        int mn = min(mn1, mn2);
        if (mn == Maxn) return false;
        if (mn == mn1) { lst = 1; ma++; s = ma; }
        else { lst = 2; mb++; s = mb; }
        i = lower_bound(A.begin() + i, A.end(), mn) - A.begin();
        j = lower_bound(B.begin() + j, B.end(), mn) - B.begin();
    }
    return i == A.size() && j == B.size() && (lst == 1 && ma > mb || lst == 2 && ma < mb);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int num; scanf("%d", &num);
        if (num == 1) A.push_back(i);
        else B.push_back(i);
    }
    int s;
    for (int t = 1; t < Maxn; t++)
        if (getS(t, s)) res.push_back(ii(s, t));
    sort(res.begin(), res.end());
    printf("%d\n", res.size());
    for (int i = 0; i < res.size(); i++)
        printf("%d %d\n", res[i].first, res[i].second);
    return 0;
}