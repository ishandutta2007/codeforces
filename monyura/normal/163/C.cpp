#pragma comment(linker,"/STACK:128000000")
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
//typedef pair<ll,ll> pll;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(x) (x).begin(),(x).end()
#define movmax(A,B) {if(A<(B)) A=(B);}
#define movmin(A,B) {if(A>(B)) A=(B);}
//#define x first
//#define y second

const double PI=acos(-1.0);
template<class T> T SQR(const T &a){return a*a;}

typedef pair<ll,int> pll;

int main()
{
	int n,l,v1,v2;
	cin>>n>>l>>v1>>v2;
	ll d=l*ll(v2);
	ll M=2*l*ll(v1+v2);
	pll A[200200];
	rep(i,0,n)
	{
		cin>>A[i].first;
		A[i].first*=(v1+v2);
		A[i].second=-1;
	}
	rep(i,0,n)
		A[i+n]=pll((A[i].first-d+M)%M,1);
	sort(A,A+2*n);
	A[2*n]=A[0];
	ll Ans[100100]={0};
	int pos=0;
	int cnt=0;
	while (pos<2*n && A[pos].first<d)
	{
		if (A[pos].second==-1) cnt++;
		pos++;
	}
	rep(i,0,2*n)
	{
		cnt+=A[i].second;
		ll curr=(A[i+1].first-A[i].first)%M;
		if (curr<0) curr+=M;
		Ans[cnt]+=curr;
	}
	rep(i,0,n+1)
		printf("%.10lf\n",Ans[i]/double(M));
	return 0;
}

/*
ab
adb
*/