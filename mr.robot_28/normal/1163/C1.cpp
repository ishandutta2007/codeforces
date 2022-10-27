#include<iostream>
#include<cmath>
#include<map>
#include<fstream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;
int nod(int a, int b)
{
	if(a *b == 0)
	{
		return a + b;
	}
	else if(a > b)
	{
		return nod(a % b, b);
	}
	else
	{
		return nod(a, b % a);
	}
}
main()
{
	#define int long long
	int n;
	cin >> n;
	vector <pair <int, int> > A;
	for(int i =0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		A.push_back({x, y});
	}
	vector <bool> used(n);
	int cnt = 0, sum = 0;
	map <pair <int, int>, set <int> > P;
	for(int i = 0; i < n; i++)
	{
		used[i] = true;
		for(int j = i + 1; j < n; j++)
		{
			int A1 = A[j].second - A[i].second;
			int B1 = A[i].first - A[j].first;
			int C1 = - A[i].first * A1 - B1 * A[i].second;
			int t = nod(abs(A1), nod(abs(B1), abs(C1)));
			if(A1 < 0)
			{
				t *= -1;
			}
			if(P[{A1 / t, B1 / t}].find(C1 / t) == P[{A1 / t, B1 / t}].end())
			{
				cnt += sum - P[{A1 / t, B1 / t}].size();
				P[{A1 / t, B1 / t}].insert(C1 / t);
				sum++;
			}
		}
	}
	cout << cnt;
    return 0;
}