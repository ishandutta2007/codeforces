#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int n;
char typ[Maxn];
int val[Maxn];
vector <int> S;
int pnt;
int res[Maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < 2 * n; i++) {
        scanf(" %c", &typ[i]);
        if (typ[i] == '+') S.push_back(pnt++);
        else if (typ[i] == '-') {
            scanf("%d", &val[i]);
            if (S.empty()) { printf("NO\n"); return 0; }
            res[S.back()] = val[i];
            S.pop_back();
        }
    }
    priority_queue <int> Q;
    pnt = 0;
    for (int i = 0; i < 2 * n; i++)
        if (typ[i] == '+')
            Q.push(-res[pnt++]);
        else {
            int my = -Q.top(); Q.pop();
            if (my != val[i]) { printf("NO\n"); return 0; }
        }
    printf("YES\n");
    for (int i = 0; i < n; i++)
        printf("%d%c", res[i], i + 1 < n? ' ': '\n');
    return 0;
}