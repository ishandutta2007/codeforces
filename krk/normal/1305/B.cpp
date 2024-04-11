#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;

int n;
char str[Maxn];
bool tk[Maxn];
vector <vector <int> > res;

int main()
{
    scanf("%s", str + 1); n = strlen(str + 1);
    while (true) {
        int l = 1, r = n;
        vector <int> tmp;
        while (l < r)
            if (str[l] != '(' || tk[l]) l++;
            else if (str[r] != ')' || tk[r]) r--;
            else {
                tmp.push_back(l);
                tmp.push_back(r);
                tk[l] = tk[r] = true;
                l++; r--;
            }
        sort(tmp.begin(), tmp.end());
        if (tmp.empty()) break;
        res.push_back(tmp);
    }
    printf("%d\n", int(res.size()));
    for (int i = 0; i < res.size(); i++) {
        printf("%d\n", int(res[i].size()));
        for (int j = 0; j < res[i].size(); j++)
            printf("%d%c", res[i][j], j + 1 < res[i].size()? ' ': '\n');
    }
    return 0;
}