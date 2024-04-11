#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void read(int &digit)
{
	digit=0;
	char c;
	for (c=getchar();(c<'0' || c>'9') && c!='-';c=getchar());
	bool type=false;
	if (c=='-')
		type=true,c=getchar();
	for (;c>='0' && c<='9';digit=digit*10+c-'0',c=getchar());
	if (type==true)
		digit=-digit;
}

#define maxn 32010
int a,b,n;
int f[maxn][31];
int check(int a,int b)
{
	if (a==1 && (1<<b)>=n)	return -2;
	ll num=1;
	for (int i=1;i<=b;i++)
	{
		num=num*a;
		if (num>=n)	return 1;
	}
	if (b==1 && 1LL*a*a>n)	return (n-a+1)&1;
	if (f[a][b]!=-1)	return f[a][b];
	int x=check(a+1,b),y=check(a,b+1);
	if (x==1 && y==1)	f[a][b]=0;else
	if (x==0 || y==0)	f[a][b]=1;else f[a][b]=-2;
	return f[a][b];
}
int main()
{
	read(a),read(b),read(n);
	if(b*log(a)>=log(double(n)))
	{
		printf("Stas\n");
		return 0;
	}
	memset(f,-1,sizeof(f));
	int q=check(a,b);
	if (q==1)	printf("Masha\n");else
	if (q==0)	printf("Stas\n");else
	printf("Missing\n");
	return 0;
}