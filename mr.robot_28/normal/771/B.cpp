#include<bits/stdc++.h>
 
using namespace std;
vector <int> dsu, rang;
int pred(int a)
{
	if(a == dsu[a])
	{
		return a;
	}
	return dsu[a] = pred(dsu[a]);
}
void unite(int a, int b)
{
	a = pred(a);
	b = pred(b);
	if(a != b)
	{
		if(rang[a] > rang[b])
		{
			swap(a, b);
		}
		dsu[b] = a;
		rang[a] += rang[b];
	}
}
signed main(){
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	dsu.resize(n);
	rang.resize(n);
	for(int i = 0; i < n; i++)
	{
		rang[i] = 1;
		dsu[i] = i;
	}
	vector <bool> flag(n - k + 1);
	for(int i = 0; i < n - k + 1; i++)
	{
		string s;
		cin >> s;
		if(s == "YES")
		{
			flag[i] = 1;
		}
		else
		{
			flag[i] = 0;
		}
	}
	int cnt = 0;
	vector <int> number(n, -1);
	for(int i = 0; i < n - k + 1; i++)
	{
		if(!flag[i])
		{
			int r = i;
			for(int j = i; j < n - k + 1; j++)
			{
				if(flag[j])
				{
					break;
				}
				r = j;
			}
			if(r <= i + k - 2 && i != 0)
			{
				unite(r, i + k - 1);
				i = r;
				continue;
			}
			int p = r + 1;
			unite(p, p - 1);
			for(int j = p - 2; j >= i + k - 2; j--)
			{
				number[j] = cnt;
				unite(j, j + 1);
			}
			cnt++;
			i = r;
		}
	}
	for(int i = 0; i < n; i++)
	{
		cout << "A";
		if(pred(i) < 26)
		{
			cout << char('a' + pred(i)) << " "; 
		}
		else
		{
			cout << "a" << char('a' + pred(i) - 26) << " ";
		}
	}
	return 0;
}