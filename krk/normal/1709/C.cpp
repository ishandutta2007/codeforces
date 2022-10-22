#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
char str[Maxn];
int slen;
vector <int> V;

bool Check()
{
    int st = 0;
    for (int i = 0; i < slen; i++) {
        st += str[i] == '('? 1: -1;
        if (st < 0) return false;
    }
    return true;
}

bool Solve()
{
    int st = 0;
    for (int i = 0; i < slen; i++)
        if (str[i] == '(') st++;
        else if (str[i] == ')') st--;
        else V.push_back(i);
    int m = V.size();
    int num = m - st;
    if (num % 2) return false;
    int op = num / 2;
    int cl = m - op;
    if (op < 0 || op > m) return false;
    for (int i = 0; i < op; i++)
        str[V[i]] = '(';
    for (int i = op; i < V.size(); i++)
        str[V[i]] = ')';
    if (!Check()) return false;
    if (op == 0 || op == m) return true;
    swap(str[V[op - 1]], str[V[op]]);
    return !Check();
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%s", str);
        slen = strlen(str);
        V.clear();
        if (Solve()) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}