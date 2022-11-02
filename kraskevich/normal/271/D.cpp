#include <algorithm>
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <cstdio>
#include <string.h>
#include <vector>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <sstream>

using namespace std;

const int N = 1500 * 1500;

struct node
{
    int go[26];
    void clean()
    {
        fill(go, go + 26, -1);
    }
};

int sz = 1;
node tr[N];
char isGood[1500 + 10];
char s[1500 + 10];
int k;
int len;

void init()
{
    for (int i = 0; i < N; ++i)
        tr[i].clean();
}

void add(int pos)
{
    int bad = 0;
    int v = 0;
    for (int i = pos; i < len; ++i)
    {
        int id = (int)s[i] - 'a';
        if (isGood[id] == '0')
            ++bad;
        if (bad > k)
            break;
        if (tr[v].go[id] == -1)
        {
            tr[v].go[id] = sz++;
        }
        v = tr[v].go[id];
    }
}

void solve()
{
    init();

    scanf("%s", s);
    scanf("%s", isGood);
    scanf("%d", &k);

    len = strlen(s);
    for (int i = 0; i < len; ++i)
        add(i);

    printf("%d", sz - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    solve();


    return 0;

}