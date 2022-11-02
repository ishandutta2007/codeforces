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

int *F;



int main()
{	
	int n;
	cin>>n;
	int *xorf=new int[n+1];
	int *F=new int[n+1];
	bool *mex=new bool[2*n+2];
	int *R=new int[n+1];
	xorf[0]=0;
	int ans;
	for (int i=1;i<=n;i++)
	{
		int pred=int(sqrt(double(i)))*2+1;
		R[i]=0;
		memset(mex,0,pred);
		for (int j=2;j*j-j<2*i && j<i;j++)
		{
			if ((2*i-j*j+j)%(2*j)!=0) continue;
			int a1=(2*i-j*j+j)/(2*j);
			int curr=xorf[a1+j-1]^xorf[a1-1];
			if (R[i]==0 && curr==0) R[i]=j;
			mex[curr]=1;
		}
		for (int j=0;j<pred;j++)
			if (!mex[j])
			{
				F[i]=j;
				break;
			}
		xorf[i]=xorf[i-1]^F[i];
	}
	if (F[n]==0) puts("-1");
	else printf("%d\n",R[n]);
	return 0;      
}