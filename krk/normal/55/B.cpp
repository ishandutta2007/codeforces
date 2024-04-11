#include <iostream>
using namespace std;

typedef long long ll;

ll a, b, c, d, best = 10000000000000000LL;
char op[3];

ll Res(ll a, ll b, char c)
{
     if (c == '+') return a + b;
     else return a * b;
}

void Search(int lvl, ll a, ll b = 0, ll c = 0, ll d = 0)
{
     if (lvl == 0) {
             Search(1, Res(a, b, op[0]), c, d);
             Search(1, Res(a, c, op[0]), b, d);
             Search(1, Res(a, d, op[0]), b, c);
             Search(1, Res(b, c, op[0]), a, d);
             Search(1, Res(b, d, op[0]), a, c);
             Search(1, Res(c, d, op[0]), a, b);
     } else if (lvl == 1) {
            Search(2, Res(a, b, op[1]), c);
            Search(2, Res(a, c, op[1]), b);
            Search(2, Res(b, c, op[1]), a);
     } else if (lvl == 2) Search(3, Res(a, b, op[2]));
     else if (a < best) best = a;
}

int main()
{
    cin >> a >> b >> c >> d;
    cin >> op[0] >> op[1] >> op[2];
    Search(0, a, b, c, d);
    cout << best << endl;
    return 0;
}