#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <memory.h>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;
#define fin for (i=0; i<n; i++)
typedef long long li;
typedef long double ld;
#define mp make_pair
typedef pair <int, int> pi;
typedef vector <int> vi;
const ld PI=3.14159265358979323846264338327950288419716939937510;
void prepare ()
{
#ifdef _DEBUG
	freopen ("in.txt", "r", stdin);
#endif
}




set < vector <char> > d;
pi q=mp(30, 30);
int a, b;
char s[30][30];
int main ()
{
	prepare ();
	int t=0;
	cin>>a>>b;
	int i, j;
	for (i=0; i<a;i++)
		for (j=0; j<b; j++)
			cin>>s[i][j];
	for (i=1; i<=a; i++)
		for (j=1; j<=b; j++)
		{
			
			if (a%i==0 && b%j==0)
			{
				d.clear();
				int z=0;
				for (int k=0; k<a/i; k++)
				{

					for (int w=0; w<b/j; w++)
					{
						int u=d.size();
						vector <char> e(0);
						for (int o=0; o<i; o++)
							for (int p=0; p<j; p++)
							{
								e.push_back(s[k*i+o][w*j+p]);
							}
						d.insert(e);
						if (u==d.size())
						{
							z=1;
							break;
						}
						e.resize(0);
						d.erase(e);
						for (int o=i-1; o>=0; o--)
							for (int p=j-1; p>=0; p--)
							{
								e.push_back(s[k*i+o][w*j+p]);
							}
						d.insert(e);
						if (u==d.size())
						{
							z=1;
							break;
						}
						if (i==j)
						{
							d.erase (e);
							e.resize(0);
							for (int p=0; p<j; p++)
							for (int o=i-1; o>=0; o--)
							{
								e.push_back(s[k*i+o][w*j+p]);
							}
							d.insert (e);
							if (u==d.size())
							{
								z=1;
								break;
							}
							d.erase (e);
							e.resize(0);
							for (int o=j-1; o>=0; o--)
							for (int p=0; p<i; p++)
							{
								e.push_back(s[k*i+p][w*j+o]);
							}
							d.insert (e);
							if (u==d.size())
							{
								z=1;
								break;
							}
						}
					}
					if (z==1)
						break;
				}
				if (z==0)
					t++;
				if (z==0 && q.first*q.second>i*j)
					q=mp(i, j);
			}
		}
		cout<<t<<endl;
		cout<<q.first<<" "<<q.second;
	return 0;
}