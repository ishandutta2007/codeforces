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
const int N = 3010;
int t, n;
char s[N];
int a[N];
int main()
{
	scanf("%d", &t);
	rep(amo, 1, t)
	{
		scanf("%d", &n);
		scanf("%s", s + 1);
		rep(i, 1, n) a[i] = s[i] - '0';
		int flag1 = 0, flag2 = 0;
		rep(i, 1, n) 
		{
			if(i % 2 == 1) flag1 |= (a[i] & 1);
			else flag2 |= ((a[i] & 1) ^ 1);
		}
		if(n % 2 == 1) 
		{
			if(flag1) printf("1\n");
			else printf("2\n");
		}
		else
		{
			if(flag2) printf("2\n");
			else printf("1\n");
		}
	}
	return 0;
}