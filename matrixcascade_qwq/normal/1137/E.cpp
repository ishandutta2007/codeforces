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
int b;
const int eps=1e-7;
struct node
{
	int x,y;
	node(int xx=0,int yy=0):x(xx),y(yy){}
	node operator - (const node &a)const
	{
		return node(x-a.x,y-a.y);
	}
	double operator * (const node &a)const
	{
		return(double)x*a.y-(double)y*a.x;
	}
}sta[1010101];
int top=0;
int f(node x)
{
	return k*x.x+x.y+b;
}
signed main()
{
	n=read(),m=read();
	sta[++top]=node();
	while(m--)
	{
		int opt=read();
		if(opt==1)
		{
			top=0;
			sta[++top]=node();
			n+=read();
			k=0;
			b=0;
		}
		else if(opt==2)
		{
			node nw=node(n,-(k*n+b));
			n+=read();
			while(top>1&&(nw-sta[top-1])*(sta[top]-sta[top-1])>-eps)--top;
			sta[++top]=nw;
		}
		else
		{
			b+=read();
			k+=read();
		}
		while(top>1&&f(sta[top])>=f(sta[top-1]))--top;
		cout<<sta[top].x+1<<" "<<f(sta[top])<<endl;
	}
}