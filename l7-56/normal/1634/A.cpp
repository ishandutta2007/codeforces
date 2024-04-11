#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int maxn = 110;
int n,k;
char s[maxn];
void work() {
    scanf("%d%d%s", &n, &k, s + 1);
    bool flag = 1;
    for (int l = 1, r = n; l < r && flag; ++l, --r)
        flag &= (s[l] == s[r]);
    if (k == 0) printf("1\n");
    else if (flag) printf("1\n");
    else printf("2\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) work();
	return 0;
}