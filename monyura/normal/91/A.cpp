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

int main()
{
	char *s1=new char[10001];
	char *s2=new char[1e6+1];
	typedef vector<int> vi;
	vi A[300];
	scanf(" %s",s1);
	scanf(" %s",s2);
	for (int i=0;s1[i];i++)
		A[s1[i]].push_back(i);
	int n1=strlen(s1);
	int n2=strlen(s2);
	pii *D=new pii[n2];
	bool ok=true;
	D[0].first=1;
	if (A[s2[0]].size()!=0)
		D[0].second=A[s2[0]][0];
	else
		ok=false;
	vi::iterator iter;
	if (ok)
		rep(i,1,n2)
		{
			int prev=D[i-1].second+1;
			if (A[s2[i]].size()==0)
			{
				ok=false;
				break;
			}
			if ((iter=lower_bound(A[s2[i]].begin(),A[s2[i]].end(),prev))!=A[s2[i]].end())
			{
				D[i]=D[i-1];
				D[i].second=*iter;
			}
			else
			{
				D[i].first=D[i-1].first+1;
				D[i].second=A[s2[i]][0];
			}
		}
	if (ok) printf("%d\n",D[n2-1].first);
	else printf("-1\n");
	return 0;	
}
/*
a
a

*/