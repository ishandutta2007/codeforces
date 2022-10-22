#include<iostream>
#include<cstdio>
#define int long long
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
int fm[15],ms[15]={0,2,3,5,7,11,13,17,19,23,29};
int x,y,z,sth,gcd; 
bool exgcd(int a,int b)
{
    if(b==0)
    {
    	if(z%a!=0)return false;
        x=z/a;
        gcd=a;
        y=0;
        return true;
    }
    if(!exgcd(b,a%b))return false;
    sth=x;
    x=y;
    y=sth-a/b*y;
    while(x<0)
    {
        x+=b/gcd;
        y-=a/gcd;
    }
    while(x>=b/gcd)
    {
        x-=b/gcd;
        y+=a/gcd;
    }
    return true;
}
int findgcd(int n,int m)
{
	while(n^=m^=n^=m%=n);
	return m;
}
signed main()
{
	int ans=1,tx;
	for(int i=1;i<=9;i++)ans=ans*ms[i];
	int t;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
	for(int i=1;i<=23;i++)
	{
		printf("? %lld %lld\n",i,i+ans);
		fflush(stdout);
		tx=read();
		//tx=findgcd(8+i+ans,8+i+2*ans); 
		for(int j=1;j<=9;j++)
		{
			if(tx%ms[j]==0)fm[j]=(ms[j]-i%ms[j])%ms[j];
		}
	}
	int ys=0,mod=1,xx,yy;
	for(int i=1;i<=9;i++)
    {
        yy=ms[i];
        xx=fm[i];
        //printf("%lld %lld\n",yy,xx);
        //if(i==1&&k==100000&&yy==4&&xx==1){printf("785779359157\n");return 0;}
        z=((xx-ys)%yy+yy)%yy;
        exgcd(mod%yy,yy);
        ys=mod*x+ys;
        mod*=yy/gcd;
       // printf("%lld %lld\n",ys,mod);
    }
    while(1)
    {
    	printf("? %lld %lld\n",29-ys%29,58-ys%29);
    	fflush(stdout);
    	tx=read();
    	//tx=findgcd(29-ys%29+8+ans,58-ys%29+8+ans);
    	if(tx!=29)ys+=ans;
    	else break;
	}
    printf("! %lld\n",ys);
    fflush(stdout);
	}
	return 0;
}