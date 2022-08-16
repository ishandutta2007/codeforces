#include<cstdio>
#include<iostream>

using namespace std;

const int INF=1000000000;

int n,s;
int c3,c4,c5;

void init()
{
	cin>>n>>s;
	while (n--)
	{
		int x;
		cin>>x;
		if (x==3) ++c3;
		if (x==4) ++c4;
		if (x==5) ++c5;
	}
}

int ans=INF,pk3,pk4,pk5;

int getabs(int x)
{
	return (x>=0)?x:-x;
}

int gcd(int a,int b)
{
	return (!b)?a:gcd(b,a%b);
}

void exgcd(int a,int b,int &x,int &y,int s)
{
	if (!b)
	{
		x=s/a;
		y=0;
		return;
	}
	int tx,ty;
	exgcd(b,a%b,tx,ty,s);
	x=ty;
	y=tx-a/b*ty;
}

void check(int k3,int k4,int k5)
{
	int get=getabs(c3*k3-c4*k4)+getabs(c4*k4-c5*k5);
	if (get<ans)
	{
		ans=get;
		pk3=k3;
		pk4=k4;
		pk5=k5;
	}
}

void check_1(int k4)
//c3*k3-c4*k4>=0&&c4*k4-c5*k5>=0
//x=c4*k4/c3<=k3<=k4
//k4<=k5<=c4*k4/c5=y
//f(k3,k4,k5)=c3*k3-c5*k5
//c3*k3+c5*k5=s-c4*k4
//x<=k3+p*(c/c3)<=k4
//k4<=k5-p*(c/c5)<=y
//c3*(k3+p*(c/c3))-c5*(k5-p*(c/c5))=c3*k3-c5*k5+2*c*p
{
	long double x=c4*k4/(long double)c3;
	long double y=c4*k4/(long double)c5;
	if (x>k4) return;
	if (k4>y) return;
	if ((s-c4*k4)%gcd(c3,c5)) return;
	int k3,k5;
	exgcd(c3,c5,k3,k5,s-c4*k4);
	long double c=c3*c5/gcd(c3,c5);
	long double L,R;
	L=max((x-k3)/(c/c3),(k5-y)/(c/c5));
	R=min((k4-k3)/(c/c3),(k5-k4)/(c/c5));
	for (int i=L-1;i<=R+1;++i)
		if (L<=i&&i<=R)
		{
			check(k3+i*(c/c3),k4,k5-i*(c/c5));
			return;
		}
}

void check_2(int k4)
//c3*k3-c4*k4>=0&&c4*k4-c5*k5<=0
//x=c4*k4/c3<=k3<=k4
//y=max(k4,c4*k4/c5)<=k5
//f(k3,k4,k5)=c3*k3-c4*k4+c5*k5-c4*k4=s-3*c4*k4
//c3*k3+c5*k5=s-c4*k4
//x<=k3+p*(c/c3)<=k4
//y<=k5-p*(c/c5)
{
	long double x=c4*k4/(long double)c3;
	long double y=max((long double)k4,c4*k4/(long double)c5);
	if (x>k4) return;
	if ((s-c4*k4)%gcd(c3,c5)) return;
	int k3,k5;
	exgcd(c3,c5,k3,k5,s-c4*k4);
	long double c=c3*c5/gcd(c3,c5);
	long double L,R;
	L=(x-k3)/(c/c3);
	R=min((k4-k3)/(c/c3),(k5-y)/(c/c5));
	for (int i=L-1;i<=R+1;++i)
		if (L<=i&&i<=R)
		{
			check(k3+i*(c/c3),k4,k5-i*(c/c5));
			return;
		}
}

void check_3(int k4)
//c3*k3-c4*k4<=0&&c4*k4-c5*k5>=0
//0<=k3<=min(k4,c4*k4/c3)=x
//k4<=k5<=c4*k4/c5=y
//f(k3,k4,k5)=c4*k4-c3*k3+c4*k4-c5*k5=3*c4*k4-s
//c3*k3+c5*k5=s-c4*k4
//0<=k3+p*(c/c3)<=x
//k4<=k5-p*(c/c5)<=y
{
	long double x=min((long double)k4,c4*k4/(long double)c3);
	long double y=c4*k4/(long double)c5;
	if (k4>y) return;
	if ((s-c4*k4)%gcd(c3,c5)) return;
	int k3,k5;
	exgcd(c3,c5,k3,k5,s-c4*k4);
	long double c=c3*c5/gcd(c3,c5);
	long double L,R;
	L=max(-k3/(c/c3),(k5-y)/(c/c5));
	R=min((x-k3)/(c/c3),(k5-k4)/(c/c5));
	for (int i=L-1;i<=R+1;++i)
		if (L<=i&&i<=R)
		{
			check(k3+i*(c/c3),k4,k5-i*(c/c5));
			return;
		}
}

void check_4(int k4)
//c3*k3-c4*k4<=0&&c4*k4-c5*k5<=0
//0<=k3<=min(k4,c4*k4/c3)=x
//y=max(k4,c4*k4/c5)<=k5
//f(k3,k4,k5)=c5*k5-c3*k3
//c3*k3+c5*k5=s-c4*k4
//0<=k3+p*(c/c3)<=x
//y<=k5-p*(c/c5)
//-(c3*(k3+p*(c/c3))-c5*(k5-p*(c/c5)))=-(c3*k3-c5*k5+2*c*p)
{
	long double x=min((long double)k4,c4*k4/(long double)c3);
	long double y=max((long double)k4,c4*k4/(long double)c5);
	if ((s-c4*k4)%gcd(c3,c5)) return;
	int k3,k5;
	exgcd(c3,c5,k3,k5,s-c4*k4);
	long double c=c3*c5/gcd(c3,c5);
	long double L,R;
	L=-k3/(c/c3);
	R=min((x-k3)/(c/c3),(k5-y)/(c/c5));
	for (int i=R+1;i>=L-1;--i)
		if (L<=i&&i<=R)
		{
			check(k3+i*(c/c3),k4,k5-i*(c/c5));
			return;
		}
}

void work()
{
	if (s%c5==0)
	{
		int k3=0,k4=0,k5=s/c5;
		check(k3,k4,k5);
	}
	for (int k4=1;c4*k4<=s;++k4)
	{
		check_1(k4);
		check_2(k4);
		check_3(k4);
		check_4(k4);
	}
	if (ans==INF)
		puts("-1");
	else
		printf("%d %d %d\n",pk3,pk4,pk5);
}

int main()
{
	init();
	work();
	return 0;
}