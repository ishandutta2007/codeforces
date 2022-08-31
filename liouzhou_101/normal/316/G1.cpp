#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<sstream>
#include<bitset>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;

#define X first
#define Y second

int n;
string s;
set<string> H;
string p[12];
int l[12],r[12];
int pp[100010];

int main()
{
	cin>>s>>n;
	for (int i=1;i<=n;++i)
		cin>>p[i]>>l[i]>>r[i];
	for (int i=0;i<s.size();++i)
		for (int j=i;j<s.size();++j)
		{
			string t=s.substr(i,j-i+1);
			int len=t.size();
			for (int k=2;k<=len;++k)
			{
				int x=pp[k-1];
				while (x)
				{
					if (t[k-1]==t[x]) break;
					x=pp[x];
				}
				pp[k]=x+(t[k-1]==t[x]);
			}
			int ff=0;
			for (int k=1;k<=n;++k)
			{
				int x=0,flag=0;
				for (int c=0;c<p[k].size();++c)
				{
					while (p[k][c]!=t[x])
					{
						x=pp[x];
						if (!x) break;
					}
					x=x+(p[k][c]==t[x]);
					if (x==len) ++flag;
				}
				if (flag>=l[k]&&flag<=r[k]) continue;
				ff=1;
				break;
			}
			if (!ff) H.insert(t);
		}
	cout<<H.size()<<endl;
	/*
	for (set<string>::iterator it=H.begin();it!=H.end();++it)
		cout<<*it<<endl;
	*/
	return 0;
}