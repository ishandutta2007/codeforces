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

int main()
{
	int A[301][301];
	int Can[301]={0};
	int n;
	cin>>n;
	rep(i,0,n)
		rep(j,0,n)
			scanf("%d",&A[i][j]);
	int P[303]={0};
	rep(i,0,n)
		scanf("%d",P+i);
	int C[303]={0};
	rep(i,0,n)
	{
		rep(j,0,i)
			if (P[j]<P[i])
			{
				Can[P[i]]=P[j];
				C[P[i]]++;
			}
	}
	int res[301];
	rep(i,0,n)
		rep(j,0,n)
		{
			if (A[i][j]!=i+1 && (C[A[i][j]]==0 || C[A[i][j]]==1 && Can[A[i][j]]==i+1))
			{
				res[i]=A[i][j];
				break;
			}
		}
	rep(i,0,n)
		printf("%d ",res[i]);
	printf("\n");
	return 0;
} 

/*
9
1 2 3 3 3 3 3 3 3 
*/