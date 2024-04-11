#include <bits/stdc++.h>
using namespace std;

typedef pair <int, char> ic;

const int Maxn = 1005;

int n;
char str[Maxn];
vector <ic> seq;

char Ask1(int ind)
{
    printf("? 1 %d\n", ind); fflush(stdout);
    char ch; scanf(" %c", &ch);
    return ch;
}

int Ask2(int lef, int rig)
{
    printf("? 2 %d %d\n", lef, rig); fflush(stdout);
    int res; scanf("%d", &res);
    return res;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int lef = 0, rig = int(seq.size()) - 1;
        while (lef <= rig) {
            int mid = lef + rig >> 1;
            if (Ask2(seq[mid].first, i) == int(seq.size()) - mid)
                lef = mid + 1;
            else rig = mid - 1;
        }
        if (rig < 0) {
            str[i] = Ask1(i);
            seq.push_back(ic(i, str[i]));
        } else {
            str[i] = seq[rig].second;
            seq.erase(seq.begin() + rig);
            seq.push_back(ic(i, str[i]));
        }
    }
    str[n + 1] = '\0';
    printf("! %s\n", str + 1);
    fflush(stdout);
    return 0;
}