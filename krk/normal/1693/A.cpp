#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int T;
int n;
int a[Maxn];

bool Check()
{
    ll st = 0;
    for (int i = 0; i < n; i++) {
        st += a[i];
        if (st < 0) return false;
        if (st == 0) {
            for (int j = i + 1; j < n; j++)
                if (a[j] != 0) return false;
            return true;
        }
    }
    return st == 0;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        printf("%s\n", Check()? "Yes": "No");
    }
    return 0;
}