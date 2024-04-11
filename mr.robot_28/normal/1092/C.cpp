#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
using namespace std;
bool cmp(pair <string, int> first, pair<string, int> second)
{
	return first.first.size() < second.first.size();
}
int main()
{
	int n;
	cin >> n;
	vector < pair <string,int> > A(2 * n - 2);
	for(int i =0; i < 2 * n - 2; i++)
	{
		cin >> A[i].first;
		A[i].second = i;
	}
	sort(A.begin(), A.end(), cmp);
	string a = "", b = "";
	string a1 = "", b1 = "", a2 = "", b2 = "";
	string h = "", g = "";
	bool k = true, l = true;
	vector <char> Q(2 * n - 2), W(2 * n - 2);
	for(int i = 2 * n - 3; i >=0; i-=2)
	{
		if(i == 2 * n - 3)
		{
			string y1 = A[i].first, y = A[i - 1].first;
			a1 = A[i].first + y[y.size() - 1];
			b1 = y1[0] + A[i - 1].first;
			if(a1 == b1)
			{
				Q[A[i].second]  = 'P';
				Q[A[i - 1].second] = 'S'; 
				a = a1;
			}
			a2 = A[i - 1].first + y1[y1.size() - 1];
			b2 = y[0] + A[i].first;
			if(a2 == b2)
			{
				b = a2;
				W[A[i].second] = 'S';
				W[A[i - 1].second] = 'P';
			}
		}
		else
		{
			a1 = A[i].first;
			b1 = A[i - 1].first;
			bool p =true, e = true;
			for(int j = 0; j < a1.size(); j++)
			{
				if(a1[j] != a[j] || b1[b1.size() - 1 - j] != a[a.size() - 1 - j])
				{
					p = false;
				}
				if(a1[a1.size() - 1 - j] != a[a.size() - 1 - j] || b1[j] != a[j])
				{
					e = false;
				}
			}
			if(k && p)
			{
				Q[A[i].second] = 'P';
				Q[A[i - 1].second] = 'S';
			}
			else if(e && k)
			{
				Q[A[i].second] = 'S';
				Q[A[i - 1].second] = 'P';
			}
			else
			{
				k = false;
			}
			p =true, e = true;
			for(int j = 0; j < b1.size(); j++)
			{
				if(a1[j] != b[j] || b1[b1.size() - 1 - j] != b[b.size() - 1 - j])
				{
					p = false;
				}
				if(a1[a1.size() - 1 - j] != b[b.size() - 1 - j] || b1[j] != b[j])
				{
					e = false;
				}
			}
			if(p && l)
			{
				W[A[i].second] = 'P';
				W[A[i - 1].second] = 'S';
			}
			else if(e && l)
			{
				W[A[i].second] = 'S';
				W[A[i - 1].second] = 'P';
			}
			else
			{
				l = false;
			}
		}
	}
	if(k)
	{
		for(int i = 0; i < 2 * n - 2; i++)
		{
			cout << Q[i];
		}
	}
	else
	{
		for(int i = 0; i < 2 * n - 2; i++)
		{
			cout << W[i];
		}
	}
	return 0;
}