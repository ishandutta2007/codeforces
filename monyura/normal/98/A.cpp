#pragma comment(linker,"/STACK:6500000")
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

bool B[6][6][6][6][6][6]={0};

int D[6];
int F[6]={3,0,1,2,4,5};
int L[6]={0,4,2,5,3,1};
int R[6]={0,5,2,4,1,3};
int Rot[6]={4,1,5,3,2,0};

bool go(int *A)
{
	bool ok=false;
	rep(i,0,4)
	{
		rep(j,0,6)
			D[j]=A[Rot[j]];
		if (!B[D[0]][D[1]][D[2]][D[3]][D[4]][D[5]]) ok=true;
		B[D[0]][D[1]][D[2]][D[3]][D[4]][D[5]]=1;
		memcpy(A,D,24);
	}
	return ok;
}

int main()
{
	int n,m;
	cin>>n>>m;
	char str[7];
	scanf("%s",str);
	int val[300]={0};
	char tmp[7]="ROYGBV";
	rep(i,0,6) val[tmp[i]]=i;
	int A[6];
	int C[6];
	int perm[6]={0,1,2,3,4,5};
	bool last=false;
	int cnt=0;
	while (1)
	{
		rep(i,0,6)
			A[i]=val[str[perm[i]]];
		rep(i,0,6)	C[i]=A[L[i]];
		bool fnd=go(C);
		rep(i,0,6) C[i]=A[R[i]];
		if (go(C)) fnd=true;
		rep(i,0,4)
		{
			rep(j,0,6)	C[j]=A[F[j]];
			if (go(C)) fnd=true;
			memcpy(A,C,24);
		}
		if (fnd) cnt++;
		if (last) break;
		if (!next_permutation(perm,perm+6)) last=true;
	}
	cout<<cnt<<endl;
    return 0;      
}
/*
0 0 2 4

*/