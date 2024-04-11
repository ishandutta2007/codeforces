#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 1000005;

int n;
char str[Maxn];
vector <int> P, A;
int nxt[2 * Maxn];

bool Check(int x)
{
    set <int> S;
    S.insert(A[0]);
    for (int i = 0; i < P.size(); i++) {
        while (!S.empty() && P[i] - x > *S.begin())
            S.erase(S.begin());
        if (S.empty()) return false;
        vector <int> add;
        if (i > 0 && *S.begin() < P[i - 1]) {
            int ind = max(nxt[P[i - 1] + x + 1], nxt[P[i] + 1]);
            if (ind >= A.size()) return true;
            add.push_back(A[ind]);
        } else if (*S.begin() < P[i]) {
            int ind = nxt[P[i] + 1];
            if (ind >= A.size()) return true;
            add.push_back(A[ind]);
        }
        set <int>::iterator it = S.lower_bound(P[i]);
        if (it != S.end() && P[i] + x >= *it) {
            int ind = nxt[P[i] + x + 1];
            if (ind >= A.size()) return true;
            add.push_back(A[ind]);
        }
        for (int j = 0; j < add.size(); j++)
            S.insert(add[j]);
    }
    return false;
}

int main()
{
    scanf("%d", &n);
    scanf("%s", str);
    for (int i = 0; i < n; i++)
        if (str[i] == '*') A.push_back(i);
        else if (str[i] == 'P') P.push_back(i);
    if (P.size() == 1) {
        int ind = lower_bound(A.begin(), A.end(), P[0]) - A.begin();
        ii res1 = ii(ind, -1);
        if (ind > 0) res1.second = P[0] - A[0];
        ii res2 = ii(int(A.size()) - ind, -1);
        if (ind < A.size()) res2.second = A.back() - P[0];
        if (res1.first < res2.first || res1.first == res2.first && res1.second > res2.second)
            swap(res1, res2);
        printf("%d %d\n", res1.first, res1.second);
        return 0;
    }
    int lst = -1;
    for (int i = 0; i < A.size(); i++) {
        for (int j = lst + 1; j <= A[i]; j++)
            nxt[j] = i;
        lst = A[i];
    }
    for (int i = lst + 1; i < 2 * Maxn; i++)
        nxt[i] = A.size();
    int lef = 1, rig = n;
    while (lef <= rig) {
        int mid = lef + rig >> 1;
        if (Check(mid)) rig = mid - 1;
        else lef = mid + 1;
    }
    printf("%d %d\n", int(A.size()), lef);
    return 0;
}