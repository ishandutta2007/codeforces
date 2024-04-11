#include<cstdio>
#include<cassert>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5,M=(1<<20)+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,a[N],k,x[N],y[N],z[N],c[25],xx[25],yy[25],zz[25],m;
bool fail=false;
void op(int u,int v,int w)
{
	x[k]=u;y[k]=v;z[k]=w;++k;
	a[u]^=1;a[v]^=1;a[w]^=1;
}
void bruteforce(int i)
{
	int s=0,full=(1<<(n-i))-1;
	assert(n-i<11);
	for(int j=n-1;j>=i;--j)s=s<<1^a[j];
	for(int j=7,i=0;j<=full;j<<=1,++i)xx[m]=i,yy[m]=i+1,zz[m]=i+2,c[m++]=j;
	for(int j=21,i=0;j<=full;j<<=1,++i)xx[m]=i,yy[m]=i+2,zz[m]=i+4,c[m++]=j;
	for(int j=73,i=0;j<=full;j<<=1,++i)xx[m]=i,yy[m]=i+3,zz[m]=i+6,c[m++]=j;
	for(int j=273,i=0;j<=full;j<<=1,++i)xx[m]=i,yy[m]=i+4,zz[m]=i+8,c[m++]=j;
	assert(m<21);
	F(j,0,1<<m)
	{
		int tot=0;
		F(kk,0,m)if(j>>kk&1)tot^=c[kk];
		if(tot==s)
		{
			F(kk,0,m)if(j>>kk&1)op(xx[kk]+i,yy[kk]+i,zz[kk]+i);
			F(j,i,n)assert(a[j]==0);
			return;
		}
	}
	fail=true;
}
int main()
{
	read(n);
	F(i,0,n)read(a[i]);
	if(n<=10)bruteforce(0);
	else
	{
		int i=0;
		for(;i+10<n;i+=6)
		{
			int s=a[i]<<5|a[i+1]<<4|a[i+2]<<3|a[i+3]<<2|a[i+4]<<1|a[i+5];
			switch(s)
			{
				case 0: break;
				case 1: op(i+5,i+6,i+7);break;
				case 2: op(i+4,i+6,i+8);break;
				case 3: op(i+4,i+5,i+6);break;
				case 4: op(i+3,i+6,i+9);break;
				case 5: op(i+3,i+5,i+7);break;
				case 6: op(i+4,i+5,i+6);op(i+3,i+5,i+7);break;
				case 7: op(i+3,i+4,i+5);break;
				case 8: op(i+2,i+6,i+10);break;
				case 9: op(i+2,i+5,i+8);break;
				case 10: op(i+2,i+4,i+6);break;
				case 11: op(i+2,i+4,i+6);op(i+5,i+6,i+7);break;
				case 12: op(i+2,i+3,i+4);op(i+4,i+6,i+8);break;
				case 13: op(i+3,i+5,i+7);op(i+2,i+6,i+10);break;
				case 14: op(i+2,i+3,i+4);break;
				case 15: op(i+2,i+3,i+4);op(i+5,i+6,i+7);break;
				case 16: op(i+1,i+3,i+5);op(i+3,i+5,i+7);break;
				case 17: op(i+1,i+5,i+9);break;
				case 18: op(i+1,i+4,i+7);break;
				case 19: op(i+1,i+4,i+7);op(i+5,i+6,i+7);break;
				case 20: op(i+1,i+3,i+5);op(i+5,i+6,i+7);break;
				case 21: op(i+1,i+3,i+5);break;
				case 22: op(i+1,i+5,i+9);op(i+3,i+4,i+5);break;
				case 23: op(i+1,i+4,i+7);op(i+3,i+5,i+7);break;
				case 24: op(i+1,i+2,i+3);op(i+3,i+6,i+9);break;
				case 25: op(i+1,i+5,i+9);op(i+2,i+6,i+10);break;
				case 26: op(i+1,i+4,i+7);op(i+2,i+6,i+10);break;
				case 27: op(i+1,i+4,i+7);op(i+2,i+5,i+8);break;
				case 28: op(i+1,i+2,i+3);break;
				case 29: op(i+1,i+2,i+3);op(i+5,i+6,i+7);break;
				case 30: op(i+1,i+2,i+3);op(i+4,i+6,i+8);break;
				case 31: op(i+1,i+2,i+3);op(i+4,i+5,i+6);break;
				case 32: op(i,i+2,i+4);op(i+2,i+4,i+6);break;
				case 33: op(i,i+5,i+10);break;
				case 34: op(i,i+4,i+8);break;
				case 35: op(i,i+4,i+8);op(i+5,i+6,i+7);break;
				case 36: op(i,i+3,i+6);break;
				case 37: op(i,i+3,i+6);op(i+5,i+6,i+7);break;
				case 38: op(i,i+3,i+6);op(i+4,i+6,i+8);break;
				case 39: op(i,i+3,i+6);op(i+4,i+5,i+6);break;
				case 40: op(i,i+2,i+4);op(i+4,i+6,i+8);break;
				case 41: op(i,i+2,i+4);op(i+4,i+5,i+6);break;
				case 42: op(i,i+2,i+4);break;
				case 43: op(i,i+2,i+4);op(i+5,i+6,i+7);break;
				case 44: op(i,i+3,i+6);op(i+2,i+6,i+10);break;
				case 45: op(i,i+3,i+6);op(i+2,i+5,i+8);break;
				case 46: op(i,i+2,i+4);op(i+3,i+6,i+9);break;
				case 47: op(i,i+2,i+4);op(i+3,i+5,i+7);break;
				case 48: op(i,i+1,i+2);op(i+2,i+6,i+10);break;
				case 49: op(i,i+1,i+2);op(i+2,i+5,i+8);break;
				case 50: op(i,i+1,i+2);op(i+2,i+4,i+6);break;
				case 51: op(i,i+4,i+8);op(i+1,i+5,i+9);break;
				case 52: op(i,i+5,i+10);op(i+1,i+3,i+5);break;
				case 53: op(i,i+3,i+6);op(i+1,i+5,i+9);break;
				case 54: op(i,i+1,i+2);op(i+2,i+3,i+4);break;
				case 55: op(i,i+4,i+8);op(i+1,i+3,i+5);break;
				case 56: op(i,i+1,i+2);break;
				case 57: op(i,i+1,i+2);op(i+5,i+6,i+7);break;
				case 58: op(i,i+1,i+2);op(i+4,i+6,i+8);break;
				case 59: op(i,i+1,i+2);op(i+4,i+5,i+6);break;
				case 60: op(i,i+1,i+2);op(i+3,i+6,i+9);break;
				case 61: op(i,i+1,i+2);op(i+3,i+5,i+7);break;
				case 62: op(i,i+4,i+8);op(i+1,i+2,i+3);break;
				case 63: op(i,i+1,i+2);op(i+3,i+4,i+5);break;
			}
			assert(!(a[i]|a[i+1]|a[i+2]|a[i+3]|a[i+4]|a[i+5]));
		}
		if(i>n-8)i=n-8;
		bruteforce(i);
	}
	if(fail)puts("No");
	else
	{
		puts("Yes");
		printf("%d\n",k);
		F(i,0,k)printf("%d %d %d\n",x[i]+1,y[i]+1,z[i]+1);
	}
	return 0;
}