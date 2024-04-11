#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
double h,m,s,t1,t2;
double ss,sm,sh;
bool ck1(double a,double b,double c)
{return a>=b&&a<=c;}
bool ck2()
{return ((ck1(ss,t1,t2)||ck1(sm,t1,t2)||ck1(sh,t1,t2))&&t1<=t2);}
bool ck3(double a)
{return a>=t1&&a<=360;}
bool ck4(double a)
{return a>=0&&a<=t2;}
bool ck5(double a)
{return ck3(a)||ck4(a);}
int main()
{
	scanf("%lf %lf %lf %lf %lf",&h,&m,&s,&t1,&t2);
	t1*=30,t2*=30;
	ss=6*s,sm=6*m+s/10;
	h=(int)h%12;
	sh=h*30+m/2+s/120;
	if(ck2()||(t1>t2&&(ck5(ss)||ck5(sm)||ck5(sh))))
	{
		swap(t1,t2);
		if(ck2()||(t1>t2&&(ck5(ss)||ck5(sm)||ck5(sh))))
		cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	else cout<<"YES"<<endl;
}