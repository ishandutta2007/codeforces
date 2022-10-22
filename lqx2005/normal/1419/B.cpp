#include<bits/stdc++.h>
#define rep(x, L, R) for(int x = (L), _x = (R); x <= _x; x++)
#define per(x, R, L) for(int x = (R), _x = (L); x >= _x; x--)
#define mpr make_pair
#define x(v) (v).first
#define y(v) (v).second
#define siz(v) (int)(v).size()
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef double db;
int t;
ll x;
int main()
{
scanf("%d", &t);
rep(amo, 1, t)
{
scanf("%lld", &x);
ll now = 0, ans = 0;
for(;;)
{
now = now * 2 + 1;
if(x >= (now + 1) * now / 2) x -= (now + 1) * now / 2, ans++;
else break;
}
printf("%lld\n", ans);
}
return 0;
}