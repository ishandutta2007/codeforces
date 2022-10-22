#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;

int n;
int a[Maxn];
vector <ii> seq;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    int r = 1;
    vector <int> twos, threes;
    for (int i = 1; i <= n; i++)
        if (a[i] == 0) ;
        else if (a[i] == 1)
            if (twos.empty() && threes.empty()) { seq.push_back(ii(r, i)); r++; continue; }
            else if (!twos.empty()) {
                int lst = twos.back(); twos.pop_back();
                seq.push_back(ii(r, lst));
                seq.push_back(ii(r, i));
                r++;
                lst = -1;
                continue;
            } else {
                int lst = threes.back(); threes.pop_back();
                seq.push_back(ii(r, lst));
                seq.push_back(ii(r, i));
                r++;
                seq.push_back(ii(r, i));
                r++;
                lst = -1;
                continue;
            }
        else if (a[i] == 2) {
            if (!threes.empty()) {
                int lst = threes.back(); threes.pop_back();
                seq.push_back(ii(r, lst));
                seq.push_back(ii(r, i));
                r++;
            }
            twos.push_back(i);
        } else if (a[i] == 3) {
            if (!threes.empty()) {
                int lst = threes.back(); threes.pop_back();
                seq.push_back(ii(r, lst));
                seq.push_back(ii(r, i));
                r++;
            }
            threes.push_back(i);
        }
    if (twos.empty() && threes.empty()) {
        printf("%d\n", int(seq.size()));
        for (int i = 0; i < seq.size(); i++)
            printf("%d %d\n", seq[i].first, seq[i].second);
    } else printf("-1\n");
    return 0;
}