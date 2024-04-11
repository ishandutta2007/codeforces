#include<bits/stdc++.h>
#define rep(x, L, R) for(int x = (L), _x = (R); x <= _x; x++)
#define per(x, R, L) for(int x = (R), _x = (L); x >= _x; x--)
#define mpr make_pair
#define x(v) (v).first
#define y(v) (v).second
#define siz(v) (int)(v).size()
#define pb push_back
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef double db;
int n, t;
int main()
{
	scanf("%d", &t);
	for(int amo = 1; amo <= t; amo++)
	{
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				if(i == j || (i) % n + 1 == j) printf("1 ");
				else printf("0 ");
			}
			printf("\n");
		}
	}
	return 0;
}