#pragma comment(linker,"/STACK:64000000")
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
	int UD[2001][2001]={0};
	int LR[2001][2001]={0};
	char A[2002][2002];
	int n;
	cin>>n;
	rep(i,0,n)
	{
		scanf(" %s",A[i]);
		rep(j,0,n)
			A[i][j]-='0';
	}
	int res=0;
	rep(i,0,n)
	{
		for (int j=n-1;j>i;j--)
		{
			int ud=0;
			if (i>0) ud=UD[i-1][j];
			int lr=0;
			if (j<n-1) lr=LR[i][j+1];
			if (((lr+ud)&1)!=A[i][j])
			{
				++res;
				++ud;
				++lr;
			}
			UD[i][j]=ud;
			LR[i][j]=lr;
		}
	}
	for (int i=n-1;i>=0;i--)
	{
		rep(j,0,i)
		{
			int ud=0;
			if (i<n-1) ud=UD[i+1][j];
			int lr=0;
			if (j>0) lr=LR[i][j-1];
			if (((lr+ud)&1)!=A[i][j])
			{
				++res;
				++ud;
				++lr;
			}
			UD[i][j]=ud;
			LR[i][j]=lr;
		}
	}
	rep(i,0,n)
	{
		int sum=0;
		if (i>0) sum+=UD[i-1][i]+LR[i][i-1];
		if (i<n-1) sum+=UD[i+1][i]+LR[i][i+1];
		if ((sum&1)!=A[i][i])
			++res;
	}
	printf("%d\n",res);
    return 0;
} 
/*
5
11110
00010
00101
00011
00001

4
1000
1000
1000
1111

3
100
100
111

3
000
000
000
*/