#include <bits/stdc++.h>
#define int long long
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
signed main() {
	int n;
	cin >> n;
	vector <pair <int, int> > A(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i].first >> A[i].second;
	}
	set <pair <pair <int, int>, int > > ST;
	vector <pair <pair <int, int>, int> > K;
	for(int i =0; i < n; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			int x1 = A[i].first, y1 = A[i].second, x2 = A[j].first, y2 = A[j].second;
			int a = y2 - y1, b = x1 - x2;
			int c = - a * x1 - b * y1;
			int k = nod(nod(abs(a), abs(b)), abs(c));
			if(a < 0 || a == 0 && b < 0)
			{
				k = -k;
			}
			a = a / k;
			b = b / k;
			c = c / k;
			if(ST.find({{a, b}, c}) == ST.end())
			{
				K.push_back({{a, b}, c});
				ST.insert({{a, b}, c});
			}
		}
	}
	sort(K.begin(), K.end());
	int ans = 0;
	for(int i = 0; i < K.size(); i++)
	{
		int i1 = i;
		while(i < K.size() && K[i].first == K[i1].first)
		{
			i++;
		}
		i--;
		int l = i - i1 + 1;
		ans += (K.size() - i1 - l) * l;
	}
	cout << ans;
	return 0;
}