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
#define x first
#define y second

const double PI=acos(-1.0);

int main()
{
	char A[2002]={0};
	char B[2002]={0};
	scanf(" %s %s",A,B);
	int n=strlen(A);
	int m=strlen(B);
	int res=1e9;
	
	bool inv=false;
	if (n<m)
	{
		inv=true;
		swap(n,m);
		char T[2002]={0};
		memcpy(T,A,sizeof(T));
		memcpy(A,B,sizeof(A));
		memcpy(B,T,sizeof(B));
	}
	rep(i,0,n-m+1)
	{
		int curr=0;
		rep(j,0,m)
			curr+=A[i+j]!=B[j];
		if (inv) curr+=n-m;
		res=min(curr,res);
	}
	int st=1;
	rep(i,n-m+1,n)
	{
		int curr=0;
		rep(j,0,m)
			if (i+j<n) curr+=A[i+j]!=B[j];
		int as=1;
		if (inv) curr+=i;
		else curr+=st++;
		res=min(curr,res);
	}
	st=m-1;
	rep(i,0,m-1)
	{
		int curr=0;
		rep(k,0,i+1)
			curr+=A[k]!=B[m-1-i+k];
		if (inv) curr+=n-i-1;
		else curr+=st--;
		res=min(curr,res);
	}
	printf("%d\n",res);
	return 0;
} 

/*
cb
bda

nffvaxdmditsolfxbyquira
        ybshzefoxkqdigcjafs

ybshzefoxkqdigcjafs
nffvaxdmditsolfxbyquira


*/