#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int l1, r1, l2, r2;
int pw;

int f(int l1, int r1, int l2, int r2, int pw)
{
    if (l1 > r1 || l2 > r2 || pw == 1) return 0;
    if (l1 <= l2 && r2 <= r1) return r2 - l2 + 1;
    if (l2 <= l1 && r1 <= r2) return r1 - l1 + 1;
    int mid = pw / 2;
    int res = 0;
    if (l1 <= mid && mid <= r1 && l2 <= mid && mid <= r2) res = min(r1, r2) - max(l1, l2) + 1;
    vector <int> al, ar, bl, br;
    if (l1 < mid) { al.push_back(l1); ar.push_back(min(mid - 1, r1)); }
    if (mid < r1) { al.push_back(max(1, l1 - mid)); ar.push_back(r1 - mid); }
    if (l2 < mid) { bl.push_back(l2); br.push_back(min(mid - 1, r2)); }
    if (mid < r2) { bl.push_back(max(1, l2 - mid)); br.push_back(r2 - mid); }
    for (int i = 0; i < al.size(); i++)
        for (int j = 0; j < bl.size(); j++) res = max(res, f(al[i], ar[i], bl[j], br[j], pw / 2));
    return res;
}

int main()
{
    scanf("%d %d %d %d", &l1, &r1, &l2, &r2);
    pw = 1;
    for (int i = 0; i < 30; i++) pw *= 2;
    printf("%d\n", f(l1, r1, l2, r2, pw));
    return 0;
}