#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int n, k;
char str[Maxn];
map <int, char> stable;
char res[Maxn];
vector <int> quer;

char Not(char ch) { return ch == 'B'? 'W': 'B'; }

int main()
{
    scanf("%d %d", &n, &k);
    scanf("%s", str);
    for (int i = 0; i < n; i++) {
        int pi = (i + n - 1) % n;
        int ni = (i + 1) % n;
        if (str[i] == str[pi] || str[i] == str[ni]) {
            stable[i] = str[i];
            stable[i - n] = str[i];
            stable[i + n] = str[i];
            res[i] = str[i];
        } else quer.push_back(i);
    }
    for (int i = 0; i < quer.size(); i++) {
        char my = k % 2 == 0? str[quer[i]]: Not(str[quer[i]]);
        if (!stable.empty()) {
            map <int, char>::iterator it2 = stable.upper_bound(quer[i]);
            auto it1 = it2; it1--;
            int got = min(quer[i] - it1->first, it2->first - quer[i]);
            if (got <= k)
                if (quer[i] - it1->first == got) my = it1->second;
                else my = it2->second;
        }
        res[quer[i]] = my;
    }
    res[n] = '\0';
    printf("%s\n", res);
    return 0;
}