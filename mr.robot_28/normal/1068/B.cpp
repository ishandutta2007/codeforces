#pragma gcc optimize("O3");
#pragma gcc target("SSE4");
#include <bits/stdc++.h> 
using namespace std;
int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	long long b, count = 0;
	cin >> b;
	for(long long i = 1; i  <= sqrt(b); i++)
	{
		if(b % i == 0)
		{
			count +=2;
			if(i * i == b)
			{
				count--;
			}
		}
	}
	cout << count;
	return 0;
}