#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int q;
int n;
char S[Maxn];
deque <int> seq[3];
char T[Maxn];

bool Solve()
{
    for (int i = 0; i < n; i++) {
        int ind = T[i] - 'a';
        if (seq[ind].empty()) return false;
        if (ind == 0) {
            if (!seq[1].empty() && seq[1].front() < seq[ind].front() ||
                !seq[2].empty() && seq[2].front() < seq[ind].front())
                return false;
        } else if (ind == 1) {
            if (!seq[2].empty() && seq[2].front() < seq[ind].front())
                return false;
        } else if (!seq[0].empty() && seq[0].front() < seq[ind].front())
                return false;
        seq[ind].pop_front();
    }
    return true;
}

int main()
{
    scanf("%d", &q);
    while (q--) {
        scanf("%d", &n);
        scanf("%s", S);
        for (int i = 0; i < 3; i++)
            seq[i].clear();
        for (int i = 0; i < n; i++)
            seq[S[i] - 'a'].push_back(i);
        scanf("%s", T);
        printf("%s\n", Solve()? "YES": "NO");
    }
    return 0;
}