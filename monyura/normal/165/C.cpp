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

typedef pair<double,double> pdd;
double Eps=1e-9;

int main()
{
	int k;
	cin>>k;
	char str[1000100];
	scanf(" %s",str);
	ll res=0;
	int cnt=0;
	int Z[1000100]={0};
	int pos=0;
	int z=0;
	rep(i,0,strlen(str))
	{
		if (str[i]=='1')
		{
			cnt++;
			Z[pos++]=z;
			z=0;
		}
		else
			z++;
		if (cnt>=k)
			res+=Z[cnt-k]+1;
	}
	Z[pos++]=z;
	if (k==0)
	{
		res=0;
		rep(i,0,pos)
			res+=Z[i]*ll(Z[i]+1)/2;
	}
	cout<<res<<endl;
	return 0;
}

/*
4 0
1 2 3 4
*/