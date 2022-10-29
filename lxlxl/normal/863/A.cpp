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

const int maxn = 1100;

int n;
char str[maxn];

bool judge(const int L,const int R)
{
	int len=R-L+1;
	for(int i=1;i<=len;i++) if(str[L+i-1]!=str[R-i+1]) return false;
	return true;
}

int main()
{
	scanf("%s",str+10); int n=strlen(str+10);
	int head=10;
	bool flag=false;
	for(int i=0;i<n;i++)
	{
		if(judge(head,10+n-1)) { flag=true; break; }
		str[--head]='0';
	}
	if(flag) puts("YES");
	else puts("NO");
	
	return 0;
}