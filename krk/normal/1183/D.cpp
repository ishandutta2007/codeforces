#include <bits/stdc++.h>
using namespace std;

int q;
int n;

int main()
{
    scanf("%d", &q);
    while (q--) {
        map <int, int> M;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            int a; scanf("%d", &a);
            M[a]++;
        }
        vector <int> seq;
        for (map <int, int>::iterator it = M.begin(); it != M.end(); it++)
            seq.push_back(it->second);
        sort(seq.rbegin(), seq.rend());
        int tot = seq[0];
        int cur = seq[0];
        for (int i = 1; i < seq.size(); i++)
            if (seq[i] < cur) { tot += seq[i]; cur = seq[i]; }
            else if (cur > 0) { tot += cur - 1; cur--; }
        printf("%d\n", tot);
    }
    return 0;
}