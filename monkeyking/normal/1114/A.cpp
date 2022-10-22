#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <stack>
#define Endl endl
#define mp make_pair
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
#define abs(a) (a>0?a:-a)
typedef unsigned long long ull;
const int inf=1039074182;
using namespace std;

int main()
{
//	freopen("input.txt","r",stdin);
	int x,y,z;
	int a,b,c;
	cin>>x>>y>>z;
	cin>>a>>b>>c;
	a-=x;
	if(a<0) over("NO");
	if(a>=y)
	{
		a-=y;
		if(a+b+c>=z) cout<<"YES";else cout<<"NO";
	}
	else
	{
		y-=a;
		b-=y;
		if(b<0) over("NO");
		if(b+c>=z) cout<<"YES";else cout<<"NO";
	}
	return 0;
}