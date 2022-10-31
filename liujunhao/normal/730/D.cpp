#include<cstdio>
#include<algorithm>
#include<cstring>
#define MAXN 200000
using namespace std;
typedef long long LL;
template<class T>
void Read(T &x){
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
typedef long long LL;
LL n,r,l[MAXN+10],t[MAXN+10],bg[MAXN+10],num[MAXN+10],ans,cnt[MAXN+10],bgd[MAXN+10];
double bgp[MAXN+10];
void read(){
	Read(n),Read(r);
	int i;
	for(i=1;i<=n;i++){
		Read(l[i]);
		l[i]<<=1;
		l[i]+=l[i-1];
	}
	for(i=1;i<=n;i++)
		Read(t[i]);
}
void solve(){
	int i;
	for(i=1;i<=n;i++){
		if((l[i]-l[i-1])/2.0>t[i]){
			puts("-1");
			exit(0);
		}
		if(bgp[i]>l[i]){
			bgp[i+1]=bgp[i],bg[i+1]=bg[i];
			continue;
		}
		double rt=t[i]-(bgp[i]-l[i-1])/2,x;
		x=max(l[i]-bgp[i]-rt,0.0);
		long long num=((long long)(x+0.6)+r-1)/r;
		cnt[i]=num,ans+=num;
		if(x==0)
			bgp[i+1]=l[i],bg[i+1]=bg[i]+l[i]-bgp[i];
		else
			bgp[i+1]=bgp[i]+(rt-x)+num*r*2,bg[i+1]=bg[i]+rt-x+num*r,bgd[i]=bg[i]+rt-x;
	}
	printf("%I64d\n",ans);
	if(ans<=100000){
		int i,j;
		for(i=1;i<=n;i++)
			for(j=1;j<=cnt[i];j++){
				printf("%I64d ",bgd[i]+(j-1)*r);
			}
	}
}
int main()
{
	read();
	solve();
}