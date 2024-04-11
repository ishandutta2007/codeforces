#include<cstdio>
#include<algorithm>
#define MAXN 100000
#define INF 0x7fffffff
using namespace std;
void Read(int &x){
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
int m,n,a[MAXN+10],b[MAXN*2+10],f[MAXN+10],x;
void read(){
	Read(m),Read(n);
	int i;
	for(i=1;i<=n;i++)
		Read(a[i]),b[i]=a[i];
	for(i=1;i<=n;i++)
		b[n+i]=b[i]+m;
}
bool check(int x){
	int i;
	f[0]=-INF;
	f[1]=1;
	for(i=2;i<=n;i++){
		f[i]=-INF;
		if(f[i-1]>=a[i]-1)
			f[i]=a[i]+x;
		if(f[i-1]>=a[i]-x-1)
			f[i]=max(f[i],a[i]);
		if(f[i-2]>=a[i]-x-1)
			f[i]=max(f[i],a[i-1]+x);
	}
	if(f[n]+x>=m)
		return 1;
	f[1]=1+x,f[2]=max(1+x,a[2]);
	if(a[2]-a[1]-1>x+x)
		return 0;
	for(i=3;i<=n;i++){
		f[i]=-INF;
		if(f[i-1]>=a[i]-1)
			f[i]=a[i]+x;
		if(f[i-1]>=a[i]-x-1)
			f[i]=max(f[i],a[i]);
		if(f[i-2]>=a[i]-x-1)
			f[i]=max(f[i],a[i-1]+x);
	}
	if(f[n]>=min(m,m+a[2]-x-1))
		return 1;
	return 0;
}
int Divide_Conqure(int l,int r){
	int mid;
	while(l<r){
		mid=(l+r)>>1;
		if(check(mid))
			r=mid;
		else
			l=mid+1;
	}
	return l;
}
void solve(){
	int i,mx,p;
	mx=b[n+1]-b[n];
	p=1;
	for(i=2;i<=n;i++)
		if(b[i]-b[i-1]>mx){
			mx=b[i]-b[i-1];
			p=i;
		}
	a[1]=1;
	for(i=2;i<=n;i++){
		a[i]=a[i-1]+b[p+1]-b[p];
		p++;
	}
	printf("%d\n",Divide_Conqure(0,mx-1));
}
int main()
{
	read();
	if(n==1){
		printf("%d\n",m-1);
		return 0;
	}
	solve();
	
}