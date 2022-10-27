#include<iostream>
#include<cmath>
#include<fstream>
#include<iomanip>
#include<vector>
#include<queue>
#include<set>
using namespace std;
#define int long long
const int S = 1e9 + 7;
vector <vector <int> > dp, ch;
int rec(int a, int b)
{
	//cout << a << " " << b << endl;
	if(b < 0 || b >= dp.size() - 1) return -1;
	if(a == dp.size() -1 )
	{
		if(b == 0)
		{
			return ch[a][b] = dp[a][b] = 0;
		}
		else
		{
			return ch[a][b] = -1;
		}
	}
	if(ch[a][b] != -2) return ch[a][b];
	int a1 = rec(a + 1, b + 1);
	int a2 = rec(a + 1, b - 1);
	if(a2 == -1)
	{
		dp[a][b] = dp[a + 1][b + 1];
	}
	else if(a1 == -1)
	{
		dp[a][b] = dp[a + 1][b - 1];
	}
	else 
	{
		dp[a][b] = (dp[a + 1][b + 1] + dp[a + 1][b - 1]) % S;
	}
	if(a1 > a2)
	{
		swap(a1, a2);
	}
	if(a2 == -1)
	{
		return ch[a][b] = -1;
	}
	if(a1 != 0 && a2)
	{
		return ch[a][b] = 0;
	}
	dp[a][b] ++;
	dp[a][b] %= S;
	return ch[a][b] = 1;
}
main()
{
    int n;
    cin >> n;
    n *= 2;
   	dp.resize(n + 1, vector <int> (n + 1, -2));
	ch.resize(n + 1, vector <int> (n + 1, -2));
    rec(0, 0);
    cout << dp[0][0];
    return 0;
}