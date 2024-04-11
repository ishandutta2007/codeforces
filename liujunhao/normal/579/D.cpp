#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXN 200000
#define MAXLEN 64
long long n,a[MAXN+10],c[MAXLEN+2],k,x,d[MAXLEN+2],cnt,b[MAXN+10][MAXLEN+10],maxl,len[MAXN+10],ans;
void Read(long long &x){
	char c;
	while(c=getchar(),c!=EOF)
		if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			return;
		}
}
long long ten2two(long long a,long long *c){
	long long cnt=0;
	while(a){
		if(a&1)
			c[cnt]++;
		cnt++;
		a>>=1;
	}
	return cnt;
}
long long two2ten(long long *c){
	long long i,ret=0;
	for(i=0;i<=MAXLEN;i++){
		if(c[i])
			ret+=(long long)1<<i;
	}
	return ret;
}
int main()
{
	Read(n),Read(k),Read(x);
	long long i,t=1,l,j;
	while(k){
		if(k&1)
			t*=x;
		x*=x;
		k>>=1;
	}
	x=t;
	t=0;
	for(i=1;i<=n;i++){
		Read(a[i]);
		ans|=a[i];
		len[i]=ten2two(a[i],b[i]);
		for(j=0;j<len[i];j++)
			c[j]+=b[i][j];
		maxl=max(len[i],maxl);
	}
	for(i=1;i<=n;i++){
		memset(d,0,sizeof d);
		for(j=0;j<len[i];j++)
			c[j]-=b[i][j];
		t=a[i]*x;
		l=ten2two(t,d);
		for(j=0;j<l;j++)
			c[j]+=d[j];
		ans=max(two2ten(c),ans);
		for(j=0;j<l;j++)
			c[j]-=d[j];
		for(j=0;j<len[i];j++)
			c[j]+=b[i][j];
	}
	printf("%I64d",ans);
}