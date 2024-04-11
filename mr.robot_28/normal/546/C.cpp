#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<cmath>
#include<stack>
#include<string>
using namespace std;
int main()
{
	int n, k, m, count = 0,a, b;
	cin >> n >> k;
	queue <int> A, B;
	for(int i = 0; i < k; i++)
	{
		cin >> a;
		A.push(a);
	}
	cin >> m;
	for(int i = 0; i < m; i++)
	{
		cin >> b;
		B.push(b);
	}
	while(count <= 106)
	{
		a = A.front(); A.pop();
		b = B.front(); B.pop();
		if(a > b)
		{
			A.push(b);
			A.push(a);
		}
		else
		{
			B.push(a);
			B.push(b);
		}
		count++;
		if(A.size() == 0 || B.size() == 0)
		{
			cout << count;
			if(A.size() ==  0)
			{
				cout << " " << 2;
			}
			else
			{
				cout << " " << 1;
			}
			return 0;
		}
	}
	cout << -1;
	return 0;
}