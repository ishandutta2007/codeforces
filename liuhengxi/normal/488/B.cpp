#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,a1,a2,a3,a4;
void swp(int &x,int &y){if(x>y)x^=y^=x^=y;}
int main()
{
	read(n);
	if(n==0)
	{
		puts("YES");
		puts("1");
		puts("2");
		puts("2");
		puts("3");
	}
	if(n==1)
	{
		read(a1);
		a3=a2=a1*2;a4=a1*3;
		puts("YES");
		printf("%d\n%d\n%d\n",a2,a3,a4);
	}
	if(n==2)
	{
		read(a1);read(a2);
		swp(a1,a2);
		if(a1*3>=a2)
		{
			puts("YES");
			a4=a1*3;
			a3=a1*4-a2;
			printf("%d\n%d\n",a3,a4);
		}
		else puts("NO");
	}
	if(n==3)
	{
		read(a1);read(a2);read(a3);
		swp(a1,a2);swp(a2,a3);swp(a1,a2);
		if(a1*3==a3)
		{
			puts("YES");
			a4=a1+a3-a2;
			printf("%d\n",a4);
		}
		else if(a1*3>a3)
		{
			a4=a1*3;
			if(a1+a4==a2+a3)printf("YES\n%d\n",a4);
			else
			{
				a4=a1+a2-a3;
				if(a4*3==a3)printf("YES\n%d\n",a4);
				else puts("NO");
			}
		}
		else puts("NO");
	}
	if(n==4)
	{
		read(a1);read(a2);read(a3);read(a4);
		swp(a1,a2);swp(a2,a3);swp(a3,a4);
		swp(a1,a2);swp(a2,a3);swp(a1,a2);
		puts(a2+a3==a1+a4&&a4==a1*3?"YES":"NO");
	}
	return 0;
}