//#pragma GCC optimize("Ofast", "unroll-loops")
//#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "avx")
#include <bits/stdc++.h>
#define lll long long
#define ull unsigned long long
#define int long long
#define YES puts("YES")
#define NO puts("NO")
#define Yes puts("Yes")
#define No puts("No")
#define edl puts("")
#define mc cerr<<"qwq\n"
#define error goto gg
#define def gg:
#define rd(x) x=read()
#define opl(x) printf("%lld",x)
#define opls(x) printf("%lld ",x)
#define opd(x) printf("%d",x)
#define opds(x) printf("%d ",x)
#define ver(x) for(int i=head[x];i;i=nxt[i])
#define up(i,x,y) for(int i=x,i##end=y;i<=i##end;++i)
#define pu(i,x,y) for(int i=x,i##end=y;i>=i##end;--i)
#define ft(x) for(int i=head[x];i;i=nxt[i])
#define upn up(i,1,n)
#define upm up(j,1,m)
#define pun pu(i,n,1)
#define pum pu(j,m,1)
#define up_(x) up(i,1,x)
#define pu_(x) pu(j,x,1)
#define ep emplace_back
#define fp for(auto to:
#define pf )
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define mkp make_pair
#define fi first
#define se second
#define mii map<int,int>
#define mis map<int,string>
#define msi map<string,int>
#define mvi map<vector<int>,int>
#define miv map<int,vector<int>>
#define rdn rd(n)
#define rdm rd(m)
#define rdk rd(k)
#define pb push_back
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

#define inf 1000000000000000000ll
lll Max(lll a=-inf,lll b=-inf,lll c=-inf,lll d=-inf,lll e=-inf,lll f=-inf,lll g=-inf,lll h=-inf)
{
	return max(max(max(a,b),max(c,d)),max(max(e,f),max(g,h)));
}
lll Min(lll a=inf,lll b=inf,lll c=inf,lll d=inf,lll e=inf,lll f=inf,lll g=inf,lll h=inf)
{
	return min(min(min(a,b),min(c,d)),min(min(e,f),min(g,h)));
}
#undef inf
void chkmin(int &x,int y)
{
	if(x>y)x=y;
}
void chkmax(int &x,int y)
{
	if(x<y)x=y;
}
int a[111];
int b[111];
signed main()
{
	int T=1;
	int v1=0,v2=0;
	while(T--)
	{
		rdn;rdm;
		upn rd(a[i]);
		up(val,2,m+m)
		{
			upn b[i]=a[i]%val;
			sort(b+1,b+n+1);
			/*
			step1:2a<=b,3a<=val
			*/
			int R=val/3;
			int L=max(b[n]+1,val-m);
			v2+=max(0ll,R-L+1)*2;
			R=val/3;
			L=Max(val-b[n],b[n-1]+1,val-m);
			v1+=max(0ll,R-L+1)*2;
		//	cout<<R<<" "<<L;edl;
			/*
			step2:a==b
			*/
			if(val%2==0)
			{
				int as=0;
				int gw=val/2;
				upn
				{
					as+=b[i]/gw;
				}
				if(as%2==0)++v2;
				else ++v1;
			}
			
			/*
			step3:2a>b,3a>val,2a<val
			*/
			
			/*
			if bi == x/2  
			*/
			int w=0;
			upn if(b[i]*2==val)w=1;
			
			if(w==0)
			{
				int R=val/2;
				while(R*2>=val)--R;
				int L=val/3;
				while(3*L<=val)++L;
				upn if(b[i]*2<val)chkmax(L,b[i]+1);//cout<<L<<endl;
				int qr=m;
				upn if(b[i]*2>=val)chkmin(qr,b[i]);
				L=Max(L,val-m,val-qr);
				int gl=L;
			//	opl(R);edl;
				int ll=max(L,b[n]/2);while(2*ll<=b[n])++ll;
				/*
				 4  
				*/
				int vl=0;
				upn if(b[i]>=val-ll&&b[i]<2*ll)++vl;
				if(vl%2==0)
				{
					v2+=max(0ll,R-ll+1)*2;
				}
				else
				{
					v1+=max(0ll,R-ll+1)*2;
				}
				chkmin(R,b[n]/2);
				chkmax(gl,b[n-1]/2);
				while(gl*2<=b[n-1])++gl;
				vl=0;
			//	cout<<gl<<" "<<b[n-1]<<endl;
				upn if(b[i]>=val-gl&&b[i]<2*gl)++vl;
			//	cout<<vl%2;edl;
				if(vl%2==0)
				{
					v1+=max(R-gl+1,0ll)*2;
				//	cout<<R<<" "<<gl<<endl;
				}
			}
			
		}
		int v3=m*m-v1-v2;
		v3/=2;
		opls(v3);opls(v3);opls(v1);opls(v2);
	}
}
/*
  When you are coding,remember to:
	   - clear the arrays if a problem has many tasks.
	   - pay attention to some special cases(n=0,1).
	   - Don't code before think completely.
	   - ...
*/