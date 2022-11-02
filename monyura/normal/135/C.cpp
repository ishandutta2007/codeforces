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
	char str[100001];
	char A[100001];
	scanf(" %s",str);
	int ones=0,zero=0,un=0;
	int n=strlen(str);
	rep(i,0,n)
		if (str[i]=='0') zero++;
		else if (str[i]=='1') ones++;
		else un++;
	vector<int> res;
	if (n&1)
	{
		if (ones<=(n-2)/2+1)
			res.push_back(0);
		if (zero<=(n-2)/2)
			res.push_back(11);	
		if (ones<=n/2+1 && zero<=n/2 && n/2+1-ones + n/2 - zero==un)
		{
			int n1=n/2+1-ones;
			int n0=n/2-zero;
			strcpy(A,str);
			rep(i,0,n)
				if (A[i]=='?')
				{
					if (n1!=0)
					{
						A[i]='1';
						n1--;
					}
					else
						A[i]='0';
				}
			int p1=-1,p0=-1;
			rep(i,0,n)
			{
				if (A[i]=='0') p0=i;
				if (A[i]=='1') p1=i;
			}
			if (p1<p0)
				res.push_back(10);
			n1=n/2+1-ones;
			n0=n/2-zero;
			strcpy(A,str);
			rep(i,0,n)
				if (A[i]=='?')
				{
					if (n0!=0)
					{
						A[i]='0';
						n0--;
					}
					else
						A[i]='1';
				}
			p1=-1;p0=-1;
			rep(i,0,n)
			{
				if (A[i]=='0') p0=i;
				if (A[i]=='1') p1=i;
			}
			if (p0<p1)
				res.push_back(1);
		}
	}
	else
	{
		if (ones<=(n-2)/2)
			res.push_back(0);
		if (zero<=(n-2)/2)
			res.push_back(11);	
		if (ones<=n/2 && zero<=n/2 && n/2-ones + n/2 - zero==un)
		{
			int n1=n/2-ones;
			int n0=n/2-zero;
			strcpy(A,str);
			rep(i,0,n)
				if (A[i]=='?')
				{
					if (n1!=0)
					{
						A[i]='1';
						n1--;
					}
					else
						A[i]='0';
				}
			int p1=-1,p0=-1;
			rep(i,0,n)
			{
				if (A[i]=='0') p0=i;
				if (A[i]=='1') p1=i;
			}
			if (p1<p0)
				res.push_back(10);
			n1=n/2-ones;
			n0=n/2-zero;
			strcpy(A,str);
			rep(i,0,n)
				if (A[i]=='?')
				{
					if (n0!=0)
					{
						A[i]='0';
						n0--;
					}
					else
						A[i]='1';
				}
			p1=-1;p0=-1;
			rep(i,0,n)
			{
				if (A[i]=='0') p0=i;
				if (A[i]=='1') p1=i;
			}
			if (p0<p1)
				res.push_back(1);
		}
	}
	sort(all(res));
	rep(i,0,res.size())
		printf("%.2d\n",res[i]);
	return 0;
} 
/*
11110???
1110000?
*/