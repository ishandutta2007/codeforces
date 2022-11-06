#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
#define re register
const int mod=998244353,ha=11451403;
int k1;
struct has
{
	int key,val;
	has*nx;
}hac[1000100];
has*la[ha],*xcnt=hac;
void add(re int k,re int va)
{
	re int k1=k%ha;
	for(re has*i=la[k1];i;i=i->nx)if(i->key==k)return;
	*++xcnt=(has){k,va,la[k1]};
	la[k1]=xcnt;
}
int find(re int k)
{
	re int k1=k%ha;
	for(re has*i=la[k1];i;i=i->nx)if(i->key==k)return i->val;
	return -1;
}
struct Mix
{
	unsigned int x[110][110];
	inline Mix operator * (const Mix &A)
	{
		Mix c={{0}};
		for(re int k=1;k<=k1;k++)
		for(re int i=1;i<=k1;i++)
		if(x[i][k])
			for(re int j=1;j<=k1;j++)
			if(A.x[k][j]){
				c.x[i][j]=(c.x[i][j]+(unsigned long long)x[i][k]*A.x[k][j])%(mod-1);
			}
		return c;
	}
}A,A1;
void exgcd(re int a,re int b,re int&d,re int &x,re int &y)
{
    if(b==0)d=a,x=1,y=0;
    else exgcd(b,a%b,d,y,x),y-=a/b*x;
}

int gcd(re int a,re int b){return b?gcd(b,a%b):a;}
int inv(re int a,re int m)
{
    re int x, y, d;
    exgcd(a,m,d,x,y);
    return (x%m+m)%m;
}
const int sz=31600;
int BSGS(int b)
{
    re unsigned int g=3,cur=1,base;
    for(re int i=0;i<sz;i++,cur=((unsigned long long)cur*g)%(mod)){
        if(cur==b)return i;
        add(cur,i);
    }
    base=inv(cur,mod);
    cur=(unsigned long long)base*b%(mod);
    for(re int i=sz;i<mod-1;i+=sz,cur=((unsigned long long)cur*base)%(mod))
	{//printf("*%d\n",i);
        re int j=find(cur);
        if(j!=-1)return i+j;
    }
    return -1;
}
int pw(re int a,re int b)
{
	re int ans=1;
	for(;b;b>>=1,a=(long long)a*a%mod)if(b&1)ans=(long long)ans*a%mod;
	return ans;
}
int main()
{
	re unsigned int n,a,a1;
	re int x,y,r,d,m;
	scanf("%d",&k1);
	for(re int i=1;i<=k1;i++)
	{
		scanf("%d",&A.x[i][1]);if(i<k1)A.x[i][i+1]=1;
	}
	scanf("%d%d",&m,&n);
	m-=k1+1;A1=A;
	for(;m;m>>=1,A=A*A)if(m&1)A1=A1*A;
	a=A1.x[1][1];
	m=BSGS(n);
	if(m<0)puts("-1"),exit(0);
	exgcd(a,mod-1,r,x,y);
	if(m%r)puts("-1"),exit(0);
	x=(long long)x*(m/r)%(mod-1);d=(mod-1)/r;
	x=((long long)x+d+mod-1)%(mod-1);
	printf("%d",pw(3,x));
}