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

int C[100001][3];
bool can(int *A,int n,int k)
{
	int pos=k;
	rep(i,0,k)
		C[i][0]=A[i];
	int cnt=0;
	while (pos<n && cnt<k)
	{
		if (A[pos]<C[cnt][0])
			C[cnt++][1]=A[pos];
		pos++;
	}
	if (cnt!=k) return false;
	cnt=0;
	while (pos<n && cnt<k)
	{
		if (A[pos]<C[cnt][1])
			C[cnt++][2]=A[pos];
		pos++;
	}
	return cnt==k;
}

int main()
{
	int n;
	int A[100001];
	cin>>n;
	rep(i,0,n)
		scanf("%d",A+i);
	sort(A,A+n,greater<int>());
	int l=0,r=n/3;
	int ans=0;
	while (l<=r)
	{
		int c=(l+r)>>1;
		if (can(A,n,c))
		{
			l=c+1;
			ans=c;
		}
		else
			r=c-1;
	}
	can(A,n,ans);
	printf("%d\n",ans);
	rep(i,0,ans)
		printf("%d %d %d\n",C[i][0],C[i][1],C[i][2]);
	return 0;
} 

/*
9
1 2 3 3 3 3 3 3 3 
*/