#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define int long long
#define up(i,x,y) for(int i=x,i##end=y;i<=i##end;++i)
#define down(i,x,y) for(int i=x,i##end=y;i>=i##end;--i)
using namespace std;
int n, m, k;
int read()
{
    int s = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        s = s * 10 + ch - '0';
        ch = getchar();
    }
    return s * f;
}
int a[101010];
signed main()
{
	int T=read();
	while(T--)
	{
		string s;
		cin>>s;
		n=s.size();
		int ps=-1;
		up(i,0,n-1)
		{
			if(s[i]=='a')
			{
				ps=i;
				break;
			}
		}
		if(ps==-1)
		{
			puts("NO");
			continue;
		}
		if(n==1)
		{
			puts("YES");
			continue;
		}
		int nw='b';
		int p1=ps-1;
		int p2=ps+1;
		int tot=1;
		while(1)
		{
			if(nw-'a'==n)break;
			if(s[p1]==nw)
			{
				++nw;
				++tot;
				--p1;
			}
			else if(s[p2]==nw)
			{
				++nw;
				++tot;
				++p2;
			}
			else break;
		}
		if(tot==n)
		{
			puts("YES");
		}
		else puts("NO");
	}
}