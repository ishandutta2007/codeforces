#pragma comment(linker,"/STACK:102400000,102400000") 
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <limits>
#include <climits>
#include <cstdio>
#include <complex>
#include <numeric>
#include <cassert>
#define endl '\n'
#define PII pair<int,int>
#define	PD pair<double,double>
#define PDI pair<double,int>
#define ll long long
#define Fori(x) for(int i=0;i<x;i++)
#define Forj(x) for(int j=0;j<x;j++)
#define For1i(x) for(int i=1;i<=x;i++)
#define For1j(x) for(int j=1;j<=x;j++)
#define For(i,n) for(int i=0;i<n;i++)
#define y1 asdfeawf
using namespace std;
const int INF = 2147483647;
const int mod = 1000000007;
const double eps= 1e-8;
const long double pi = acosl(-1.0);
const int maxn = 1234567;

class Prime
{
public:
	Prime(int n)
	{
		vector<char> c(n+1);
		for(int i=2;i<=n;i++)
		{
			if(c[i]==0)
			{
				d.push_back(i);
				for(int j=i+i;j<=n;j+=i)
					c[j]=1;
			}
		}
	}
	int &operator [](unsigned n)
	{
		return d[n];
	}
	unsigned size() const
	{
		return d.size();
	}
protected:
	vector<int> d;
}prime(2000011);
//78499
int vis[200000];
int visn[2000011];
int a[100011];
const int jrq = 2000000;
void bj(int x)
{
	for(int i=x;i<=jrq;i+=x)
		visn[i] = 1;
}

bool check(int x,vector<int> &v)
{
	for(int i=0;i<prime.size();i++)
	{
		if(x%prime[i]==0)
			v.push_back(i);
		while(x%prime[i]==0)
			x/=prime[i];
		if(x<prime[i])
			break;
	}
	for(int i=0;i<v.size();i++)
		if(vis[v[i]])
			return false;
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	Fori(n)
		cin>>a[i];
	bool flag = false;
	int pos = 0;
	for(int i=0;i<n;i++)
	{
		vector<int> v;
		if(!flag)
		{
			if(check(a[i],v))
				cout<<a[i]<<" ";
			else
			{
				v.clear();
				int fk = 2;
				for(int j=a[i];;j++)
					if(visn[j]==0)
					{
						fk = j;
						break;
					}
				cout<<fk<<" ";
				check(fk,v);
				flag = true;
			}
		}
		else
		{
			while(vis[pos]) pos++;
			cout<<prime[pos]<<" ";
			vis[pos] = 1;
			continue;
		}
		for(int i=0;i<v.size();i++)
		{
			if(vis[v[i]]==0)
				bj(prime[v[i]]);
			vis[v[i]] = 1;
		}
	}
	return 0;
}