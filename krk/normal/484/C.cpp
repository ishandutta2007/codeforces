#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005;

char str[Maxn];
int n;
char res[Maxn];
int m;
int k, d;
map <int, vector <int> > M;
vector <int> tmp;

void Get(int len, int k, int d)
{
    if (M.find(len) != M.end()) return;
    if (k == len) {
        tmp.resize(len);
        int pnt = 0;
        for (int i = 0; i < d; i++)
            for (int j = i; j < len; j += d)
                tmp[pnt++] = j;
    } else {
        int a = (len + k - 1) / 2, b = (len + k) / 2;
        Get(a, k, d);
        Get(b, k, d);
        auto it1 = M.find(a);
        auto it2 = M.find(b);
        tmp.resize(len);
        for (int i = 0; i < a - (k - 1); i++)
            tmp[i] = it1->second[i];
        int st = a - (k - 1);
        for (int i = st, j = 0; i < len; i++, j++)
            if (st + it2->second[j] < a)
                tmp[i] = it1->second[st + it2->second[j]];
            else tmp[i] = st + it2->second[j];
    }
    M.insert(make_pair(len, tmp));
}

int main()
{
    scanf("%s", str);
    n = strlen(str);
    scanf("%d", &m);
    while (m--) {
        M.clear();
        scanf("%d %d", &k, &d);
        Get(n, k, d);
        auto it = M.find(n);
        for (int i = 0; i < n; i++)
            res[i] = str[it->second[i]];
        for (int i = 0; i < n; i++)
            str[i] = res[i];
        printf("%s\n", str);
    }
    return 0;
}