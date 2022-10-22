#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 505;

int T;
int n;
vector <int> res;
vector <ii> ans;
vector <int> A;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        A.resize(n);
        map <int, int> M;
        for (int i = 0; i < n; i++) {
            scanf("%d", &A[i]);
            M[A[i]]++;
        }
        bool od = false;
        for (auto it: M)
            if (it.second % 2) od = true;
        if (od) {
            printf("-1\n");
            continue;
        }
        res.clear();
        ans.clear();
        while (!A.empty()) {
            int ind = int(A.size()) - 2;
            while (A[ind] != A.back()) ind--;
            if (ind + 2 == A.size()) {
                res.push_back(2);
                A.pop_back();
                A.pop_back();
                continue;
            }
            int l = ind + 1, r = int(A.size()) - 1;
            for (int i = int(A.size()) - 1, p = ind + 1; i > ind; i--, p++)
                ans.push_back(ii(p, A[i]));
            res.push_back(2 * (int(A.size()) - ind - 1));
            reverse(A.begin() + ind + 1, A.end());
        }
        printf("%d\n", int(ans.size()));
        for (int i = 0; i < ans.size(); i++)
            printf("%d %d\n", ans[i].first, ans[i].second);
        reverse(res.begin(), res.end());
        printf("%d\n", int(res.size()));
        for (int i = 0; i < res.size(); i++)
            printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
    }
    return 0;
}