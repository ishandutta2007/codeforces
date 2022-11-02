#include <cstdio>
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

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef long double ld;
typedef pair<int,int> pii;
#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)

const double PI=acos(-1.0);
const ld Eps=1e-8;

template<class T> inline T sqr(T a){return a*a;}

int n,m,k;
int A[100];
int step=1;

int dist(int pos)
{
	if (pos==k) return 0;
	if (pos>k)
	{
		if (step==1)
			return pos-k;
		return k+pos;
	}
	if (step==-1) return k-pos;
	return n-1-k+n-1-pos;
}

int forw(int pos)
{
	if (pos==n-1) return n-1;
	return pos+1;
}

int back(int pos)
{
	if (pos==0) return 0;
	return pos-1;
}

void gok()
{
	if (step==1)
	{
		k++;
		if (k==n-1)
			step=-1;
	}
	else
	{
		k--;
		if (k==0)
			step=1;
	}
}

int main()
{
	cin>>n>>m>>k;
	m--;k--;
	char tmp[100],nap[100];
	scanf(" %s%s",tmp,nap);
	if (nap[0]=='h') step=-1;
	char str[200];
	scanf(" %s",str);
	int pos=m;
	for (int i=0;str[i+1];i++)
	{
		if (str[i]=='0')
		{
			int bestpos=back(pos);
			if (dist(pos)>dist(bestpos)) bestpos=pos;
			if (dist(forw(pos))>dist(bestpos)) bestpos=forw(pos);
			pos=bestpos;
			gok();
		}
		else
		{
			gok();
			int bestpos=pos;
			int bestdist=dist(pos);
			rep(i,0,n)
				if (dist(i)>bestdist)
				{
					bestpos=i;
					bestdist=dist(i);
				}
			pos=bestpos;
		}
		if (k==pos) 
		{
			printf("Controller %d\n",i+1);
			return 0;
		}
	}
	puts("Stowaway");
	return 0;
}
/*
2 2 1
to tail
11
*/