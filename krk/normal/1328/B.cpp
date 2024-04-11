#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
string s;

int main()
{
    scanf("%d", &T);
    while (T--) {
        int n; scanf("%d", &n);
        s = string(n, 'a');
        int k; scanf("%d", &k);
        ll my = 2;
        while (k > my * (my - 1) / 2) my++;
        s[n - my] = 'b';
        k -= (my - 1) * (my - 2) / 2;
        s[n - k] = 'b';
        printf("%s\n", s.c_str());
    }
    return 0;
}