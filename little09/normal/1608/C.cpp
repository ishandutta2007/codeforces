// By: Little09
// Problem: C. Game Master
// Contest: Codeforces - Codeforces Round #758 (Div.1 + Div. 2)
// URL: https://codeforces.com/contest/1608/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))
#define printYes puts("Yes")
#define printYES puts("YES")
#define printNo puts("No")
#define printNO puts("NO")

const ll inf=1000000000000000000; 
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m,T; 
struct point
{
	int x,y,id;
}a[N];
bool cmp(point x,point y)
{
	return x.x<y.x;
}
inline int read()
{
    int F=1,ANS=0;
	char C=getchar();
    while (C<'0'||C>'9')
	{
		if (C=='-') F=-1;
		C=getchar();
	}
    while (C>='0'&&C<='9')
	{
		ANS=ANS*10+C-'0';
		C=getchar();
	}
    return F*ANS;
}
int s[N][2],ans[N];
void work()
{
	n=read();
	for (int i=1;i<=n;i++) a[i].x=read(),a[i].id=i;
	for (int i=1;i<=n;i++) a[i].y=read();
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=n;i++) s[i][0]=max(a[i].y,s[i-1][0]);
	s[n+1][1]=2e9;
	for (int i=n;i>=1;i--) s[i][1]=min(a[i].y,s[i+1][1]);
	int u=1;
	for (int i=n;i>=1;i--)
	{
		if (s[i][1]>s[i-1][0])
		{
			u=i;
			break;
		}
	}
	for (int i=1;i<u;i++) ans[a[i].id]=0;
	for (int i=u;i<=n;i++) ans[a[i].id]=1;
	for (int i=1;i<=n;i++) cout << ans[i];
	cout << endl;
	return;
}

int main()
{
	int tp=0;
	//0 : many test cases
	//1 : one test case
	if (tp==0) T=read();
	else T=1;
	while (T--)
	{
		work();
	}
	return 0;
}