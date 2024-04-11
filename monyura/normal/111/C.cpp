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
typedef short int si;
typedef long double ld;
typedef pair<int,int> pii;
#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)

const double PI=acos(-1.0);

template<class T> inline T SQR(T a){return a*a;}

si getVal(si a,si pos)
{
	return (a>>(2*pos))&3;
}

si setVal(si a,si pos,si val)
{
	return ((~(3<<(2*pos)))&a)|(val<<(2*pos));	
}


char str[14][5]={"123*","*021","12**","*23*","113*","*11*","*13*",
					 "11**","*011","*2**","*1**","*01*","*02*","*0**"};
char fig[14][5];

int n,m;
si generateMask(si mask,si pos,si ind)
{
	si res=mask;
	for (int i=-1;i<3;i++)
	{
		if (pos+i<0 && fig[ind][i+1]!='*' || pos+i>=n && fig[ind][i+1]!='*')
			return -1;
	}
	for (int i=-1;i<3;i++)
	{
		if (pos+i>=0 && pos+i<n)
		{
			int val=getVal(mask,pos+i);
			if (fig[ind][i+1]!='*')
			{
				if (fig[ind][i+1]=='1' && val!=0 && val!=3 || fig[ind][i+1] =='2' && val!=0
					|| fig[ind][i+1]=='3' && val!=1 && val!=0) return -1;
				if (fig[ind][i+1]=='3' && val==1) 
					res=setVal(res,pos+i,2);
				else 
					res=setVal(res,pos+i,fig[ind][i+1]-'0');
			}
		}
	}
	return res;
}

int main()
{
	int mas[]={1,8,11,12,13};
	rep(i,0,5)
	{
		strcpy(fig[i],str[mas[i]]);
		str[mas[i]][0]=0;
	}
	int pos=5;
	rep(i,0,14)
		if (str[i][0]!=0)
			strcpy(fig[pos++],str[i]);
	cin>>n>>m;
	if (n>m) swap(n,m);
	int to=(1<<(2*n));
	int D[41][41][1<<12];
	rep(i,0,m+1)
		rep(j,0,n+1)
			rep(k,0,1<<(2*n))
				D[i][j][k]=1e9;
	D[0][0][0]=0;
	si curr;
	si newMask;
	int cnt;
	rep(i,0,m)
	{
		for (int j=0;j<n-1;j++)
			for (si k=0;k<to;k++)
			{
				curr=getVal(k,j);
				if (curr==1 || curr==2)
				{
					newMask=setVal(k,j,curr-1);
					if (D[i][j+1][newMask]>D[i][j][k])
						D[i][j+1][newMask]=D[i][j][k];
					continue;
				}
				if (curr==3) cnt=5;
				else cnt=14;
				for (int f=0;f<cnt;f++)
				{
					newMask=generateMask(k,j,f);
					if (newMask!=-1)
					{
						if (curr==3) newMask=setVal(newMask,j,1);
						if (D[i][j+1][newMask]>D[i][j][k]+1)
							D[i][j+1][newMask]=D[i][j][k]+1;
					}
				}				
			}
		for (si k=0;k<to;k++)
		{
			curr=getVal(k,n-1);
			if (curr==1 || curr==2)
			{
				newMask=setVal(k,n-1,curr-1);
				if (D[i+1][0][newMask]>D[i][n-1][k])
					D[i+1][0][newMask]=D[i][n-1][k];
				continue;
			}
			if (curr==3) cnt=5;
			else cnt=14;
			for (int f=0;f<cnt;f++)
			{
				newMask=generateMask(k,n-1,f);
				if (newMask!=-1)
				{
					if (curr==3) newMask=setVal(newMask,n-1,1);
					if (D[i+1][0][newMask]>D[i][n-1][k]+1)
						D[i+1][0][newMask]=D[i][n-1][k]+1;
				}
			}	
		}
	}
	printf("%d\n",int(n*m-D[m][0][0]));
	return 0;
}


/*




*/