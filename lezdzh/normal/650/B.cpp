#include<cstdio>
#include<algorithm>
using namespace std;

char s[1000001];
int c[1000001];
int main(){
	int n;
	long long a,b,t;
	scanf("%d%I64d%I64d%I64d%s",&n,&a,&b,&t,s+1);
	int ans=0;
	for(int i=1;i<=n;i++)
		c[i]=c[i-1]+(s[i]=='w');
	for(int i=1;i<=n;i++){
		long long o=t-(c[i]*b+i+a*2*(i-1));
		int l=1,r=n+1;
		while(l!=r){
			int m=l+r>>1;
			if(b*(c[n]-c[m-1])+a*(n-m+1)+(n-m+1)<=o)r=m;
			else l=m+1;
		}
		if(b*(c[n]-c[l-1])+a*(n-l+1)+(n-l+1)<=o)
			ans=max(ans,i+n-l+1);
	}
	for(int i=n+1;i;i--){
		long long o=t-((c[n]-c[i-1])*b+(n-i+1)+a*2*(n-i+1));
		int l=1,r=n;
		while(l!=r){
			int m=l+r+1>>1;
			if(b*c[m]+a*(m-1)+m<=o)l=m;
			else r=m-1;
		}
		if(b*c[l]+a*(l-1)+l<=o)
			ans=max(ans,l+n-i+1);
	}
	printf("%d\n",min(ans,n));
}