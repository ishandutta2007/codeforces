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

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef long double ld;
typedef pair<int,int> pii;
#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)

const double PI=acos(-1.0);
const ld Eps=1e-8;

template<class T> inline T sqr(T a){return a*a;}

vector<int> res;
pii get(int v)
{
	int l=0,r=res.size()-1;
	int ans=0;
	while (l<=r)
	{
		int c=(l+r)>>1;
		if (res[c]==v) return pii(c,1);
		if (res[c]>v) r=c-1;
		else if (res[c]<v) l=c+1,ans=c+1;
	}
	return pii(ans,0);
}

int main()
{
	int n,m,k,t;
	char A[3][100]={"Carrots","Kiwis","Grapes"};
	cin>>n>>m>>k>>t;
	res.reserve(k);
	rep(i,0,k)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		a--;
		b--;
		res.push_back(a*m+b);
	}
	sort(res.begin(),res.end());
	rep(i,0,t)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		a--;
		b--;
		pii in=get(a*m+b);
		if (in.second==1) puts("Waste");
		else printf("%s\n",A[(a*m+b-in.first)%3]);
	}
	return 0;
}
/*
1
4 1 2 3 4 1
*/