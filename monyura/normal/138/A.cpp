//#pragma comment(linker,"/STACK:32000000")
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

int k;
bool gl[300]={0};
bool rifm(char *a,char *b)
{
	int n=strlen(a);
	int m=strlen(b);
	int p1=-1,p2=-1;
	int l1=k,l2=k;
	for (int i=n-1;i>=0;i--)
	{
		if (gl[a[i]])
		{
			if (l1==1) 
			{
				p1=i;
				break;
			}
			else l1--;
		}
	}
	for (int i=m-1;i>=0;i--)
	{
		if (gl[b[i]])
		{
			if (l2==1) 
			{
				p2=i;
				break;
			}
			else l2--;
		}
	}
	if (p1==-1 || p2==-1) return 0;
	return (strcmp(a+p1,b+p2)==0);
}

int main()
{
	int n;
	cin>>n>>k;
	char S[4][15000];
	int res[5]={0};
	char out[5][100]={"aabb","abab","abba","aaaa","NO"};
	gl['a']=gl['e']=gl['i']=gl['o']=gl['u']=1;
	rep(i,0,n)
	{
		rep(j,0,4)
			scanf(" %s",S[j]);
		if (rifm(S[0],S[1]) && rifm(S[2],S[3]))
		{
			if (rifm(S[1],S[2]))
			{
				rep(k,0,4)
					++res[k];
			}
			else res[0]++;
		}
		else if (rifm(S[0],S[2]) && rifm(S[1],S[3]))
			res[1]++;
		else if (rifm(S[0],S[3]) && rifm(S[1],S[2]))
			res[2]++;
	}
	for (int i=3;i>=0;i--)
		if (res[i]==n)
		{
			printf("%s\n",out[i]);
			return 0;
		}
	printf("NO\n");
	return 0;
} 
/*
2 1
a
a
a
a
a
a
a
e
*/