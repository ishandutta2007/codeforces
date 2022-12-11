#include<cstdio>
#include<algorithm>
using namespace std;

int a[200002];
long long s[200002][2];
long long da(int p,int r){
	if(p&1)return -2*s[max(0,p-2)][1]+s[r][1];
	else return -2*s[p-2][0]+s[r][0];
}
int main(){
	int t;
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		if(n==1){printf("1\n");continue;}
		if(n==2){printf("%d\n",a[1]!=a[2]?2:1);continue;}
		for(int i=2;i<n;i++){
			s[i][0]=s[i-1][0];
			s[i][1]=s[i-1][1];
			if(i%2)s[i][1]+=a[i];
			else s[i][0]+=a[i];
		}
		s[n][0]=s[n-1][0];
		s[n][1]=s[n-1][1];
		s[n+1][0]=s[n-1][0];
		s[n+1][1]=s[n-1][1];
		int w=0;
		long long ans=0;
		for(int i=0;i<4;i++){
			int l=2,r=n+1;
			if(i==0)w=-a[1]-a[n],r--;
			else if(i==1)w=-a[1]+a[n];
			else if(i==2)w=a[1]-a[n],l++,r--;
			else w=a[1]+a[n],l++;
			int p=1,q=n%2?n+1:n;
			while(p<l)p+=2;
			while(q>r)q-=2;
			for(;p<=r;p+=2){
				while(q>=l&&da(p,n)+da(q,n)+w<=0)q-=2;
			//	printf("%d %lld %d %lld %d\n",p,da(p,n),q,da(q,n),w);
			//	printf("%d %d %d\n",i,p,q);
			//	printf("%d\n",q/2-(l-1)/2);
			//	printf("%d??\n",r);
				ans+=q/2-(l-1)/2;
			}
		}
		for(int i=1;i<=n;i++)
			if(-s[n][0]-s[n][1]-a[1]-a[n]+2*(a[1]+s[i][0]+s[i][1]+(i==n?a[n]:0))>0){
				//printf("!%d\n",i);
				ans++;
			}
		printf("%lld\n",ans%998244353);
	}
}