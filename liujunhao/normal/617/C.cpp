#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 2000
long long d1[MAXN+10],d2[MAXN+10],ans=0x7fffffffffffffff;
int n,x1,y1,x2,y2;
void Read(int &x){
	char c;
	bool f=0;
	while(c=getchar(),c!=EOF){
		if(c=='-')
			f=1;
		if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			if(f)
				x=-x;
			ungetc(c,stdin);
			return;
		}
	}
}
int main()
{
	Read(n),Read(x1),Read(y1),Read(x2),Read(y2);
	int i,x,y,j;
	long long t,mx2;
	for(i=1;i<=n;i++){
		Read(x),Read(y);
		d1[i]=1ll*(x1-x)*(x1-x)+1ll*(y1-y)*(y1-y);
		d2[i]=1ll*(x2-x)*(x2-x)+1ll*(y2-y)*(y2-y);
	}
	for(i=0;i<=n;i++){
		t=d1[i],mx2=0;
		for(j=1;j<=n;j++)
			if(d1[j]>d1[i])
				mx2=max(mx2,d2[j]);
		ans=min(t+mx2,ans);
	}
	printf("%I64d\n",ans);
}