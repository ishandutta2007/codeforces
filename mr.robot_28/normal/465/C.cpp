#pragma gcc optimize("O3");
#pragma gcc target("SSE4");
#include <bits/stdc++.h> 
using namespace std;
const int inf = 1e9;
bool p1 = true;
string a;
void rec(int n, int p, int i)
{
	int u = a[i] - 'a';
	//cout << i << " " << u << " " << p << endl;
	if(i == 0 && u == p - 1)
	{
		//cout << 1;
		p1 = false;
	}
	else
	{
		bool k1 = true;
		//cout << i << " " << p << " " << a[i - 1] << " " << a[i - 2] << endl;
		for(int j = u + 1; j < p; j++)
		{
			if(i == 0 || (i == 1 && a[i - 1] - 'a' != j) || (i >= 2 && a[i - 1] - 'a'!= j && a[i - 2] - 'a' != j))
			{
				k1 = false;
				a[i] = 'a' + j;
				//cout << i << " " << a[i];
				return;
			}
		}
		if(i != 0 && k1)
		{
			rec(n, p, i - 1);
			if(p1)
			{
			for(int j = 0; j < p; j++)
			{
				if(i == 0 || (i == 1 && a[i - 1] - 'a' != j) || (i >= 2 && a[i - 1] - 'a'!= j && a[i - 2] - 'a' != j))
				{
					k1 = false;
					a[i] = 'a' + j;
					return;
				}
			}
		}
		}
	}
}
int main()
{
	int n, p;
	cin >> n >> p >> a;
	rec(n, p , n - 1);
	if(!p1)
	{
		cout << "NO";
		return 0;
	}
	cout << a;
	return 0;
}