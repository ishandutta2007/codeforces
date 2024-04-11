#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

int q;
int n;

int main()
{
    scanf("%d", &q);
    while (q--) {
        map <int, ii> M;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            int a, f; scanf("%d %d", &a, &f);
            M[a].first++; M[a].second += f;
        }
        vector <ii> seq;
        for (map <int, ii>::iterator it = M.begin(); it != M.end(); it++)
            seq.push_back(it->second);
        sort(seq.rbegin(), seq.rend());
        priority_queue <int> Q;
        int cur = seq[0].first; Q.push(seq[0].second);
        int tot1 = 0, tot2 = 0;
        for (int i = 1; i < seq.size(); i++)
            if (seq[i].first >= cur) Q.push(seq[i].second);
            else {
                while (cur > seq[i].first && !Q.empty()) {
                    tot1 += cur; tot2 += min(cur, Q.top()); Q.pop();
                    cur--;
                }
                cur = seq[i].first; Q.push(seq[i].second);
            }
        while (cur > 0 && !Q.empty()) {
            tot1 += cur; tot2 += min(cur, Q.top()); Q.pop();
            cur--;
        }
        printf("%d %d\n", tot1, tot2);
    }
    return 0;
}