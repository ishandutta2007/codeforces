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
//#define x first
//#define y second

const double PI=acos(-1.0);


int main()
{
	int n,m,x,y;
	cin>>n>>m>>x>>y;
	int A[100100],B[100100];
	rep(i,0,n)
		scanf("%d",A+i);
	rep(i,0,m)
		scanf("%d",B+i);
	int p=0;
	vector<pii> res;
	for (int j=0;j<m;)
	{
		while (j<m && B[j]<A[p]-x)j++;
		if (j<m)
		{
			if (A[p]-x<=B[j] && B[j]<=A[p]+y)
			{
				res.push_back(pii(p+1,j+1));
				j++;
			}
		}
		if (p<n-1) p++;
		else break;
	}
	printf("%d\n",(int)res.size());
	rep(i,0,res.size())
		printf("%d %d\n",res[i].first,res[i].second);
	return 0;
} 

/*


*/