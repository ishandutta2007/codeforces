#include <bits/stdc++.h>
using namespace std;

typedef pair <char, int> ci;

const int Maxn = 200005;

int n;
char str[Maxn];
deque <ci> seq;
int res[Maxn];

int main()
{
    scanf("%d", &n);
    scanf("%s", str);
    for (int i = 0; i < n; i++) {
        int ind = lower_bound(seq.begin(), seq.end(), ci(str[i] + 1, 0)) - seq.begin() - 1;
        if (ind >= 0) { res[i] = seq[ind].second; seq[ind].first = str[i]; }
        else {
            seq.push_front(ci(str[i], 0));
            seq.front().second = seq.size();
            res[i] = int(seq.size());
        }
    }
    printf("%d\n", int(seq.size()));
    for (int i = 0; i < n; i++)
        printf("%d%c", res[i], i + 1 < n? ' ': '\n');
    return 0;
}