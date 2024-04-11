#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 1000005;

int mx[Maxn];
vector <int> dvs[Maxn];
int n, k;
bool tk[Maxn], dtk[Maxn];
int cur[Maxn];
priority_queue <ii> Q;
ll res;

int gcd(int x, int y) { return x? gcd(y % x, x): y; }

int F(int n)
{
    int num = n;
    while (n > 1) {
        int g = mx[n];
        num -= num / g;
        while (mx[n] == g)
            n /= g;
    }
    return num;
}

void addDiv(int d)
{
    if (dtk[d]) return;
    dtk[d] = true;
    for (int i = d; i <= n; i += d) if (!tk[i])
        if (--cur[i] == 0) {
            tk[i] = true; Q.push(ii(-F(i), -i));
        }
    int num = d;
    while (num > 1) {
        int g = mx[num];
        addDiv(d / g);
        while (mx[num] == g) num /= g;
    }
}

int main()
{
    for (int i = 1; i < Maxn; i++)
        for (int j = i; j < Maxn; j += i)
            cur[j]++;
    for (int i = 2; i < Maxn; i++) if (mx[i] == 0)
        for (int j = i; j < Maxn; j += i)
            mx[j] = i;
    scanf("%d %d", &n, &k);
    tk[1] = tk[2] = true;
    tk[3] = true; Q.push(ii(-2, -3));
    if (4 <= n) {
        tk[4] = true; Q.push(ii(-3, -4));
    }
    for (int i = 5; i <= n; i++)
        cur[i]--;
    addDiv(1);
    while (k > 0) {
        int v = -Q.top().second;
        int add = -Q.top().first; Q.pop();
        k--; res += add;
        addDiv(v);
    }
    cout << res + 1 << endl;
    return 0;
}