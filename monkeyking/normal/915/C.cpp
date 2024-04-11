#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <stack>
#define Endl endl
#define mp make_pair
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
#define srand() mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l,r) uniform_int_distribution<int>(l,r)(rng)
typedef unsigned long long ull;
const int inf=1039074182;
using namespace std;
char a[20];
char b[20];
map <int,int> m;
bool lock[20];
char key;

bool testtg()
{
	map <int,int> m2;
	for(int i=0;i<strlen(a);i++)
	{
		m[a[i]]++;
		m2[b[i]]++;
	}
	if(m==m2)
	{
		for(int i=0;i<strlen(a);i++)
		{
			a[i]=b[i];
		}
		return true;
	}
	return false;
}

string solve()
{
	map <int,int> data=m;
	int len=strlen(a);
	string res="";
	bool nless=false;
	for(int i=0;i<len;i++)
	{
		if(lock[i])
		{
			if(data[key]==0) return "";
			data[key]--;
			res+=key;
			nless=true;
			continue;
		}
		for(char c='9';c>='0';c--)
		{
			if(data[c] && (c<=b[i] || nless))
			{
				data[c]--;
				res+=c;
				break;
			}
		}
	}
	if(res.size()!=len) return "";
	return res;
}

int main()
{
//	freopen("input.txt","r",stdin);
	scanf("%s%s",a,b);
	int la=strlen(a);
	int lb=strlen(b);
	string ans="";
	if(la<lb)
	{
		sort(a,a+la);
		reverse(a,a+la);
	}
	else
	{
		if(!testtg())
		{
			for(int i=0;i<la;i++)
			{
				lock[i]=true;
				for(char c='0';c<b[i];c++)
				{
					key=c;
					ans=max(ans,solve());
				}
				lock[i]=false;
			}
			cout<<ans<<endl;
			return 0;
		}
	}
	printf("%s\n",a);
	return 0;
}