#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

int n , x , s[2] , gg;

int main()
{
	int i , j;
	cin >> n;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d",&x);
		s[x%2]++;
	}
	if (s[0])
	{
		s[0]--;
		cout << "2 ";
	}
	if (s[1] && s[1]%2 == 0)
	{
		s[1]--;
		gg = 1;
	}
	for (i = 1 ; i <= s[1] ; i++)
		printf("1 ");
	for (i = 1 ; i <= s[0] ; i++)
		printf("2 ");
	if (gg) cout << "1 ";
	cout << "\n";
	return 0;
}