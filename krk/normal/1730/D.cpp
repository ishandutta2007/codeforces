#include <bits/stdc++.h>
using namespace std;

typedef pair <char, char> cc;

const int Maxn = 100005;

int T;
int n;
char A[Maxn];
char B[Maxn];
set <cc> S;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        scanf("%s", A);
        scanf("%s", B);
        S.clear();
        for (int i = 0; i < n; i++) {
            cc p = cc(A[i], B[n - 1 - i]);
            if (p.first > p.second) swap(p.first, p.second);
            if (S.count(p)) S.erase(p);
            else S.insert(p);
        }
        if (S.empty() || S.size() == 1 && S.begin()->first == S.begin()->second)
            printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}