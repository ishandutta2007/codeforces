#include <bits/stdc++.h>
using namespace std;

int n;
string a, b;
int res;

int main()
{
    cin >> n >> a >> b;
    int l = 0, r = int(a.length()) - 1;
    while (l < r) {
        if (a[l] == a[r]) {
            if (b[l] != b[r])
                res += (b[l] != a[l]) + (b[r] != a[l]);
        }
        else if (b[l] == b[r]) res++;
        else {
            set <char> S;
            S.insert(a[l]);
            S.insert(a[r]);
            S.insert(b[l]);
            S.insert(b[r]);
            if (S.size() == 3) res++;
            else if (S.size() == 4) res += 2;
        }
        l++, r--;
    }
    if (l == r) res += a[l] != b[l];
    printf("%d\n", res);
    return 0;
}