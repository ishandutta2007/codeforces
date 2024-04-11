#include<bits/stdc++.h>
using namespace std;
#define int long long
vector <int> power;
const int N = 30;
int fa(int x, int y)
{
	if(x % 2 == 0)
	{
		if(y < power[x / 2])
		{
			return 0;
		}
		y -= power[x / 2];
		y >>= x;
		return !(y & 1);
	}
	else
	{
		if(y < power[x / 2 + 1])
		{
			return 0;
		}
		y -= power[x / 2 + 1];
		y >>= x;
		return (y & 1);
	}
}
int fb(int x, int y)
{
	if(x % 2 == 0)
	{
		if(y < power[x / 2 + 1])
		{
			return 0;
		}
		y -= power[x / 2 + 1];
		y >>= x + 1;
		return (y & 1);
	}
	else
	{
		if(y < power[x / 2])
		{
			return 0;
		}
		y -= power[x / 2];
		y >>= x - 1;
		if(y < 2)
		{
			return y ^ 1;
		}
		y >>= 1;
		return (y & 1);
	}
}
int fc(int x, int y)
{
	return fa(x, y) ^ fb(x, y);
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    power.resize(N + 1);
    power[0] = 0;
    for(int i = 1; i < N; i++)
    {
    	power[i] = power[i - 1] * 4 + 1;
	}
    int t;
    cin >> t;
    while(t--)
    {
    	int n;
    	cin >> n;
    	n--;
    	int a = 0;
    	if(n % 3 == 0)
    	{
    		for(int i = 0; i < 60; i++)
    		{
    			a |= fa(i, n / 3) << i;
			}
		}
		else if(n % 3 == 1)
		{
			for(int i = 0; i < 60; i++)
			{
				a |= fb(i, n / 3) << i;
			}
		}
		else
		{
			for(int i = 0; i < 60; i++)
			{
				a |= fc(i, n / 3) << i;
			}
		}
		cout << a << "\n";
	}
    return 0;
}