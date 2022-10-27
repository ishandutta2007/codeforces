#include<bits/stdc++.h>
using namespace std;
#define int long long
int far(int x, int y)
{
	return x * x + y * y;
}
vector <int> val;
vector <int> dsu;
vector <int> rang;
int pred(int a)
{
	if(a == dsu[a]){
		return a;
	}
	else
	{
		int to = pred(dsu[a]);
		if(to != dsu[a])
		{
			val[a] *= val[dsu[a]];
		}
		dsu[a] = to;
		return to;
	}
}
void unite(int a, int b)
{
	a = pred(a);
	b = pred(b);
	if(a != b){
		if(rang[a] < rang[b]){
			swap(a, b);
		}
		if(val[a] == -1)
		{
			val[b] *= -1;
		}
		dsu[b] = a;
		if(rang[a] == rang[b])
		{
			rang[a]++;
		}
	}
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	val.resize(n);
	dsu.resize(n);
	rang.resize(n);
	vector <pair <int, int> > x(n);
	vector <int> type(n, 1);
	int stx = 0, sty = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> x[i].first >> x[i].second;
	}
	int p = 1e6;
	p = p * p;
	vector <int> ind(n);
	for(int i = 0; i < n; i++)
	{
		ind[i] = i;
		dsu[i] = i;
		rang[i] = 1;
		val[i] = 1;
	}
	for(int i = 0; i < n - 2; i++){
		for(int j = i + 0; j < min(n, 3 + i); j++)
		{
			for(int d = j + 1; d < min(n, 3 + i); d++){
				if(far(x[j].first + x[d].first, x[j].second + x[d].second) <= p)
				{
					unite(ind[j], ind[d]);
					x[d].first += x[j].first;
					x[d].second += x[j].second;
					if(j != i)
					{
						x[i + 1] = x[i];
						ind[i + 1] = ind[i];
					}
					j = 3 + i;
					break;
				}
				else if(far(x[j].first - x[d].first, x[j].second - x[d].second) <= p)
				{	
					val[pred(ind[d])] *= -1;
					unite(ind[j], ind[d]);
					x[d].first = x[j].first - x[d].first;
					x[d].second = x[j].second - x[d].second;
					if(j != i){
						x[i + 1] = x[i];
						ind[i + 1] = ind[i];
					}
					j = 3 + i;
					break;
				}
			}
		}
	}
	int p1 = 1.5e6;
	p1 = p1 * p1;
	if(n > 1)
	{
	if(far(x[n - 2].first + x[n - 1].first, x[n - 2].second + x[n - 1].second) <= p1)
	{
		unite(ind[n -2], ind[n - 1]);
	}
	else
	{
		val[pred(ind[n - 1])] *= -1;
		unite(ind[n - 2], ind[n - 1]);
	}
	}
	for(int i = 0; i < n; i++)
	{
		int t = pred(i);
		if(t != i)
		{
			cout << val[t] * val[i] << " ";
		}
		else
		{
			cout << val[i] << " ";
		}
	}
	return 0;
}