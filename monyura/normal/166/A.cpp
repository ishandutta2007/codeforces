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
typedef pair<ll,ll> pll;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(x) (x).begin(),(x).end()
#define movmax(A,B) {if(A<(B)) A=(B);}
#define movmin(A,B) {if(A>(B)) A=(B);}
#define x first
#define y second

const double PI=acos(-1.0);
template<class T> T SQR(const T &a){return a*a;}

bool cmp(const pii &a,const pii &b)
{
	if (a.x!=b.x) return a.x>b.x;
	return a.y<b.y;
}

int main()
{
	pii A[100];
	int n,k;
	cin>>n>>k;
	rep(i,0,n)
	{
		scanf("%d%d",&A[i].x,&A[i].y);
	}
	sort(A,A+n,cmp);
	int res=0;
	rep(i,0,n)
		if (A[i]==A[k-1]) res++;
	cout<<res<<endl;
	return 0;
}

/*

*/