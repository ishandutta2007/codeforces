#include<cstdio>
#include<algorithm>
using namespace std;

int a[100001],b[100001],c[100001];
int pr[100001],nx[100001];
inline long long sq(long long w){
	return w*w;
}
inline int iin(){
	char c=0;
	int u=0;
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')u=u*10+c-'0',c=getchar();
	return u;
}
long long cc(int*a,int*b,int*c){
	for(int i=1;i<=b[0];i++){
		pr[i]=pr[i-1];
		while(pr[i]<a[0]&&a[pr[i]+1]<=b[i])
			pr[i]++;
	}
	nx[b[0]+1]=c[0]+1;
	for(int i=b[0];i;i--){
		nx[i]=nx[i+1];
		while(nx[i]>1&&c[nx[i]-1]>=b[i])
			nx[i]--;
	}
	long long ans=~0ull>>1;
	for(int i=1;i<=b[0];i++)
		if(pr[i]!=0&&nx[i]!=c[0]+1)
			ans=min(ans,sq(a[pr[i]]-b[i])+sq(c[nx[i]]-b[i])+sq(c[nx[i]]-a[pr[i]]));
	return ans;
}
int main(){
	int t;
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++){
		scanf("%d%d%d",&a[0],&b[0],&c[0]);
		for(int i=1;i<=a[0];i++)
			a[i]=iin();
		for(int i=1;i<=b[0];i++)
			b[i]=iin();
		for(int i=1;i<=c[0];i++)
			c[i]=iin();
		sort(a+1,a+a[0]+1);
		sort(b+1,b+b[0]+1);
		sort(c+1,c+c[0]+1);
		long long ans=~0ull>>1;
		ans=min(ans,cc(a,b,c));
		ans=min(ans,cc(a,c,b));
		ans=min(ans,cc(b,a,c));
		ans=min(ans,cc(b,c,a));
		ans=min(ans,cc(c,a,b));
		ans=min(ans,cc(c,b,a));
		printf("%lld\n",ans);
	}
	
}