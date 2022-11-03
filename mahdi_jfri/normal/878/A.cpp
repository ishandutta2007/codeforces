#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define bit(a , b) (((a)>>(b))&1)
const int maxn = 1e5 + 20;
const int maxb = 10;
int b[maxb][2];
int and_ , or_ , xor_;
int main()
{
	for(int i = 0; i < maxb; i++)
		for(int j = 0; j < 2; j++)
			b[i][j] = j;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		char ch;
		int x;
		cin >> ch >> x;
		for(int i = 0; i < maxb; i++)
		{
			if(ch == '|')
			{
				if(bit(x , i))
					b[i][0] = b[i][1] = 1;
			}
			if(ch == '&')
			{
				if(!bit(x , i))
					b[i][0] = b[i][1] = 0;
			}
			if(ch == '^')
			{
				if(bit(x , i))
					b[i][0] = !b[i][0] , b[i][1] = !b[i][1];
			}
		}
	}
	for(int i = maxb - 1; i >= 0; i--)
	{
		and_ *= 2;
		or_ *= 2;
		xor_ *= 2;
		if(b[i][0] == 0 && b[i][1] == 0)
		{
			continue;
		}
		if(b[i][0] == 0 && b[i][1] == 1)
		{
			and_++;
		}
		if(b[i][0] == 1 && b[i][1] == 0)
		{
			and_++;
			xor_++;
		}
		if(b[i][0] == 1 && b[i][1] == 1)
		{
			or_++;
			and_++;
		}
	}
	cout << 3 << endl;
	cout << "| " << or_ << endl;
	cout << "& " << and_ << endl;
	cout << "^ " << xor_ << endl;
}