#include<bits/stdc++.h>
#define ll long long
#define db double
#define X first
#define Y second
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rep0(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define fore(i,a) for(int i=0;i<a.size();++i)
inline int rd()
{
	char c=getchar();int x=0,w=1;
	while(!isdigit(c)&&c!='-')c=getchar();
	if(c=='-')w=-1,c=getchar();
	while(isdigit(c))x=x*10+c-48,c=getchar();
	return x*w;
}
inline void cmx(int&a,int b){a=a>b?a:b;}
inline void cmn(int&a,int b){a=a<b?a:b;}
const int N=100005;
int n,a[N],b[N],sa[N],sb[N];
int main()
{
	int T=rd();
	while(T--)
	{
		n=rd();
		rep(i,1,n)a[i]=rd();
		rep(i,1,n)b[i]=rd();
		std::sort(a+1,a+n+1);
		std::sort(b+1,b+n+1);
		rep(i,1,n)sa[i]=sa[i-1]+a[i];
		rep(i,1,n)sb[i]=sb[i-1]+b[i];
		rep(i,0,n)
		{
			int k1=n+i,k2=k1/4;
			int Sa=sa[n]+i*100-sa[k2];
			int Sb=sb[n]-sb[k2<=i?0:k2-i];
			if(Sa>=Sb){printf("%d\n",i);break;}
		}
	}
	return 0;
}