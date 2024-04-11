//MatrixCascade

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define clr(f, n) memset(f, 0, sizeof(int) * (n))
#define cpy(f, g, n) memcpy(f, g, sizeof(int) * (n))
#define rev(f, n) reverse(f, f + n)
#define pir pair<int, int>
#define mkp make_pair
#define fst it->first
#define sec it->second
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
inline void print(int *f, int len)
{
    for (int i = 0; i < len; i++)
        printf("%lld ", f[i]);
    puts("");
}
int T;

int a[1001001];
char c[1010010];
int b[1000001];
int s1[1000011],s2[1000011];
signed main()
{
	T=read();
	while(T--)
	{
		n=read();
		scanf("%s",c+1);
		int tot=0;
		up(i,1,n)b[i]=0;
		up(i,1,n)if(c[i]=='*')b[i]=1,++tot;
		a[n+1]=b[n+1]=s1[n+1]=s2[n+1]=0;
		up(i,1,n)a[i]=a[i-1]+b[i];
		if(a[n]==0)
		{
			puts("0");
			continue;
		}
		up(i,1,n)
		{
			if(b[i])s1[i]=s1[i-1]+i;
			else s1[i]=s1[i-1];
		}
		down(i,n,1)
		{
			if(b[i])s2[i]=s2[i+1]+i;
			else s2[i]=s2[i+1];
		}
		int ans=100101010101;
		up(i,1,n)
		{
			if(!b[i])continue;
			int p1=s1[i-1];
			int p2=s2[i+1];
			int t1=a[i-1];
			int t2=tot-t1-1;
		//	cout<<p1<<" "<<p2<<" "<<t1<<" "<<t2<<endl;
			int nw=i*t1-p1-t1*(t1+1)/2+p2-t2*i-t2*(t2+1)/2;
			ans=min(ans,nw);
		}
		cout<<ans<<endl;
	} 
}