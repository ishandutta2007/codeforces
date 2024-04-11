//QwQcOrZ yyds!!!
#include<bits/stdc++.h>

using namespace std;

inline int read(){
    int x = 0; char ch = getchar(); bool positive = 1;
    for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
    for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
    return positive ? x : -x;
}
inline void write(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writesp(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
    printf(" ");
}
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
    }
    write(a); puts("");
}

int T,n,a[100005],L,R;
double ans,ll,r,v1,v2,l,now;

signed main()
{
	T=read();
	while (T--)
	{
		scanf("%d%lf",&n,&r);
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		} 
		L=0;
		l=ans=0.0;
		R=n+1;
		v1=v2=1.0;
		while (L<R)
		{
			if(L+1==R)
			{
				ans+=(r-l)/(v1+v2);
				break;
			}
			if((a[L+1]-l)*v2<(r-a[R-1])*v1)
			{
				now=(a[L+1]-l)/v1;
				ans+=now;
				l=a[++L];
				r-=now*v2;
				v1++;
				if(r==a[R-1])v2++,
				R--;
			}
			else
			{
				now=(r-a[R-1])/v2;
				ans+=now;
				r=a[--R];
				l+=now*v1;
				v2++;
				if(l==a[L+1])v1++,L++;
			}
		}
		printf("%.9lf\n",ans);
	}
			
}