#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

int n;

int main()
{
	scanf("%d",&n);
	bool flag=true; int now1=0,now2=1,oth=2;
	for(int i=1;i<=n;i++)
	{
		int x; scanf("%d",&x); x--;
		if(now1!=x&&now2!=x) { flag=false; break; }
		if(now1!=x) swap(now1,now2);
		swap(now2,oth);
	}
	if(flag) puts("YES");
	else puts("NO");
	
    return 0;
}