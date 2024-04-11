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

char Res[200]={0};

ll getCnt(int s,ll k)
{
	ll D[200],P[200]={0};
	P[1]=1;
	rep(i,1,s)
	{
		memset(D,0,sizeof(D));
		if (Res[i]==')')
		{
			rep(i,0,s-1)
				D[i]=P[i+1];
		}
		else if (Res[i]=='(')
		{
			rep(i,1,s)
				D[i]=P[i-1];
		}
		else
		{
			rep(i,0,s)
			{
				if (i>0) D[i]=P[i-1];
				if (i<s-1) D[i]+=P[i+1];
				if (D[i]>k) D[i]=k+1;
			}
		}
		memcpy(P,D,sizeof(P));
	}
	return D[0];
}

int main()
{
	ll k;
	int n,m;
	cin>>n>>m>>k;
	int P[100][100];
	rep(i,0,n)
		rep(j,0,m)
			scanf("%d",&P[i][j]);
	pii pr[200];
	rep(i,0,n+m-1)
	{
		pr[i].first=1e9;
		pr[i].second=i;
	}
	rep(i,0,n)
		rep(j,0,m)
			if (pr[i+j].first>P[i][j])
				pr[i+j].first=P[i][j];
	sort(pr,pr+n+m-1);
	k--;
	rep(i,0,n+m-1)
	{
		Res[pr[i].second]='(';
		ll cnt=getCnt(n+m-1,k);
		if (k>=cnt)
		{
			Res[pr[i].second]=')';
			k-=cnt;
		}
	}
	rep(i,0,n)
	{
		rep(j,0,m)
			printf("%c",Res[i+j]);
		printf("\n");
	}
    return 0;
} 
/*

*/