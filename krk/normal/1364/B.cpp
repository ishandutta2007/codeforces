#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int T;
int n;
int p[Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        vector <int> seq;
        for (int i = 0; i < n; i++) {
            scanf("%d", &p[i]);
            while (seq.size() >= 2 &&
                (seq[int(seq.size()) - 2] < seq.back() && seq.back() < p[i] ||
                 seq[int(seq.size()) - 2] > seq.back() && seq.back() > p[i]))
                seq.pop_back();
            seq.push_back(p[i]);
        }
        printf("%d\n", int(seq.size()));
        for (int i = 0; i < seq.size(); i++)
            printf("%d%c", seq[i], i + 1 < seq.size()? ' ': '\n');
    }
    return 0;
}