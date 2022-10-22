#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll lim = (1ll << 32ll);

vector <ll> mult;
int n;
char tmp[10];
ll res;

int main()
{
    mult.push_back(1);
    scanf("%d", &n);
    while (n--) {
        scanf("%s", tmp);
        if (tmp[0] == 'f') {
            int a; scanf("%d", &a);
            mult.push_back(min(lim, mult.back() * a));
        } else if (tmp[0] == 'e') mult.pop_back();
        else res = min(lim, mult.back() + res);
    }
    if (res >= lim) printf("OVERFLOW!!!\n");
    else cout << res << endl;
    return 0;
}