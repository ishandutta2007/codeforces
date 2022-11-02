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
typedef short int si;
typedef long double ld;
typedef pair<int,int> pii;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(x) (x).begin(),(x).end()

const double PI=acos(-1.0);

template<class T> inline T SQR(T a){return a*a;}


char was[5001]={0};
int to[5001];

int n;
vector<int> curr;
vector<int> res;

char A[5001][5001];
bool dfs(int k)
{
	was[k]=1;
	curr.push_back(k);
	rep(i,0,n)
		if (A[k][i]==1)
		{
			if (was[i]==1)
			{
				for (int j=curr.size()-1;j>=0 && curr[j]!=i;j--)
					res.push_back(curr[j]);
				res.push_back(i);
				return true;
			}
			if (was[i]==0)
				if (dfs(i)) return true;
		}
	curr.pop_back();
	was[k]=2;
	return false;
}

int main()
{

	
	cin>>n;
	cin.get();
	char str[5001];
	rep(i,0,n)
	{
		gets(str);
		rep(j,0,n)
			A[i][j]=str[j]-'0';
	}
	rep(i,0,n)
		if (!was[i] && res.size()==0)
			dfs(i);
	reverse(all(res));
	rep(i,0,res.size())
		to[res[i]]=res[(i+1)%res.size()];
	int a,b,c;
	int cnt=res.size();
	if (cnt>=3)
	{
		a=res[0];b=res[1];c=res[2];
	}
	while (cnt>3)
	{
		if (A[c][a])
		{
			printf("%d %d %d",a+1,b+1,c+1);
			return 0;
		}
		b=c;
		c=to[c];
		cnt--;
	}
	if (cnt==0) 
		printf("-1\n");
	else
		printf("%d %d %d\n",a+1,b+1,c+1);
	return 0;
}


/*
5 5
1 5 4
1 3 1
1 3 4
3 1 5
4 2 5

5 5
3 1 5
4 2 5

5 4
1 2 6

*/