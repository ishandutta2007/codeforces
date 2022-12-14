#include <stdio.h>
#define MAXN 1005

int n, m;
struct BIT
{
	int c[2 * MAXN];
	void update(int x, int val)
	{
		for(; x <= 2 * n; x += (x & (-x)))
			c[x] += val;
	}
	int query(int x)
	{
		int ans = 0;
		for(; x; x -= (x & (-x)))
			ans += c[x];
		return ans;
	}
}bit;

inline bool isdigit(char x){return x >= '0' && x <= '9';}
int getint()
{
	char ch;
	int res;
	while(!isdigit(ch = getchar()));
	res = ch - '0';
	while(isdigit(ch = getchar()))
		res = res * 10 + ch - '0';
	return res;
}
int main()
{
	int i, j, t;
	n = getint();
	for(i = 1; i <= n; i ++)
		for(j = 1; j <= n; j ++)
		{
			t = getint();
			if(i == j)
				bit.update(i, t);
		}
	m = getint();
	for(i = 1; i <= m; i ++)
	{
		t = getint();
		switch(t)
		{
			case 1:
			case 2:
				j = getint();
				t = bit.query(j) - bit.query(j - 1);
				bit.update(j, t ? -1 : 1);
				break;
			case 3:
				printf("%d", bit.query(n) % 2);
				break;
		}
	}
	printf("\n");
	return 0;
}