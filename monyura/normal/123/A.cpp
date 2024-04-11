#pragma comment(linker,"/STACK:32000000")
#include <cstdio>
#include <memory>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <complex>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <fstream>
#include <functional>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned char uc;
typedef short int si;
typedef unsigned short int usi;
typedef long double ld;
typedef pair<int,int> pii;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(x) (x).begin(),(x).end()

const double PI=acos(-1.0);

template<class T> inline T SQR(T a){return a*a;}

int main()
{
	char str[1001];
	scanf(" %s",str);
	int n=strlen(str);
	sort(str,str+n);
	int simp[1001];
	int cnt=0;
	bool Can[1001]={0};
	rep(i,2,1000)
	{
		bool s=1;
		for (int j=2;j*j<=i;j++)
			if (i%j==0)
			{
				s=0;
				break;
			}
		if (s && i*2>n && i<=n)
		{
			simp[cnt++]=i;
			Can[i-1]=1;
		}
	}
	bool used[300]={0};
	int pos=0;
	Can[0]=1;
	map<char,int> mp;
	rep(i,0,n)
		mp[str[i]]++;
	char best=0;
	bool ok=1;
	rep(i,'a','z'+1)
		if (mp.find(i)!=mp.end() && mp[i]>=n-cnt-1)
			best=i;
	char str2[1001]={0};
	if (best==0)
		ok=0;
	else
	{
		rep(i,0,n)
			if (!Can[i])
			{
				str2[i]=best;
				mp[best]--;
				if (mp[best]==0)
					mp.erase(best);
			}
	}
	if (ok)
		rep(i,0,n)
			if (Can[i])
			{
				str2[i]=mp.begin()->first;
				if (mp.begin()->second!=1)
					mp.begin()->second--;
				else
					mp.erase(mp.begin());
			}
	
	if (ok)
		printf("YES\n%s\n",str2);
	else
		printf("NO\n");
	return 0;
} 
/*
adcbbbb
*/