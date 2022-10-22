#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 1000005;

int n;
map <int, int> M;
char tmp[Maxn];
int tlen;
ll res;

int Collect(int mask)
{
    map <int, int>::iterator it = M.find(mask);
    return it == M.end()? 0: it->second;
}

void Add(int mask)
{
    map <int, int>::iterator it = M.find(mask);
    if (it == M.end()) M.insert(make_pair(mask, 1));
    else it->second++;
}

int main()
{
    scanf("%d", &n);
    while (n--) {
        scanf("%s", tmp); tlen = strlen(tmp);
        int mask = 0;
        for (int i = 0; i < tlen; i++)
            mask ^= 1 << int(tmp[i] - 'a');
        res += Collect(mask);
        for (int i = 0; i < 26; i++)
            res += Collect(mask ^ 1 << i);
        Add(mask);
    }
    cout << res << endl;
    return 0;
}