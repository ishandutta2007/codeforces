#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ld ans = 1e50;

//ax^2 + bx + c = 0
ld solve(ll a, ll b, ll c) {
    if (!a) return abs(ld(c)/b);
    ld d = ld(b)*b-ld(4)*a*c;
    if (d < 0) return 1e50;
    ld d1 = (-b+sqrt(d))/(2*a);
    ld d2 = (-b-sqrt(d))/(2*a);
    return min(abs(d1), abs(d2));
}

ll a, b, c, d;

void go(int ka, int kb, int kc, int kd) {
    ans = min(ans, solve(ka*kd-kb*kc, a*kd+d*ka-b*kc-c*kb, a*d-b*c));
}

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> a >> b >> c >> d;

    go(1, -1, -1, 1);

    for (int ka=-1; ka<=1; ka+=2)
    for (int kb=-1; kb<=1; kb+=2)
    for (int kc=-1; kc<=1; kc+=2)
    for (int kd=-1; kd<=1; kd+=2)
    go(ka, kb, kc, kd);
    cout << fixed << setprecision(10) << ans;
}