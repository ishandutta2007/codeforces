#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 1000005;

int res = 1000000005;
int n, m;
int my[Maxn];
map <ii, int> M;

int Ask(int r, int c)
{
    r++; c++;
    auto it = M.find(ii(r, c));
    if (it != M.end()) return it->second;
    printf("? %d %d\n", r, c); fflush(stdout);
    int got; scanf("%d", &got);
    res = min(res, got);
    M.insert(make_pair(ii(r, c), got));
    return got;
}

vector <int> Compress(const vector <int> &R, const vector <int> &C)
{
    vector <int> res;
    for (int k = 0; k < C.size(); k++) {
        while (!res.empty() && Ask(R[int(res.size()) - 1], res.back()) > Ask(R[int(res.size()) - 1], C[k]))
            res.pop_back();
        if (res.size() < R.size())
            res.push_back(C[k]);
    }
    return res;
}

void Solve(const vector <int> &R, const vector <int> &C)
{
    if (R.empty()) return;
    if (R.size() < C.size()) {
        Solve(R, Compress(R, C));
        return;
    }
    vector <int> othR;
    for (int i = 1; i < R.size(); i += 2)
        othR.push_back(R[i]);
    Solve(othR, C);
    for (int i = 0; i < R.size(); i += 2) {
        int lef = i > 0? my[R[i - 1]]: 0;
        int rig = i + 1 < R.size()? my[R[i + 1]]: m - 1;
        lef = lower_bound(C.begin(), C.end(), lef) - C.begin();
        rig = upper_bound(C.begin(), C.end(), rig) - C.begin() - 1;
        my[R[i]] = lef;
        for (int j = lef; j <= rig; j++)
            if (Ask(R[i], C[j]) < Ask(R[i], my[R[i]]))
                my[R[i]] = C[j];
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    vector <int> R, C;
    for (int i = 0; i < n; i++)
        R.push_back(i);
    for (int i = 0; i < m; i++)
        C.push_back(i);
    Solve(R, C);
    printf("! %d\n", res);
    return 0;
}