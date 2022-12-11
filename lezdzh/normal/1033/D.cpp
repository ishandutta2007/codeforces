#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

const int md=998244353;
struct nd{long long a;int z;}w[10001];
int wt;
bool operator<(nd u,nd v){
	return u.a<v.a;
}
long long a[501];
long long gcd(long long x,long long y){
	return y?gcd(y,x%y):x;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%I64d",&a[i]);
	int ans=1;
	for(int i=1;i<=n;i++){
		long long c1=0,c2=0,c3=0;
		for(int j=20;j>=0;j--)
			if((c1+(1<<j))*(c1+(1<<j))*(c1+(1<<j))<=a[i])c1+=1<<j;
		for(int j=15;j>=0;j--)
			if((unsigned long long)(c2+(1<<j))*(c2+(1<<j))*(c2+(1<<j))*(c2+(1<<j))<=a[i])c2+=1<<j;
		c3=sqrt(a[i]);
		while(c3*c3>a[i])c3--;
		while(c3*c3<a[i])c3++;
		if(c1*c1*c1==a[i])w[++wt]=(nd){c1,3};
		else if(c2*c2*c2*c2==a[i])w[++wt]=(nd){c2,4};
		else if(c3*c3==a[i])w[++wt]=(nd){c3,2};
		else{
			int z=1;
			for(int j=1;j<=n;j++){
				long long u=gcd(a[i],a[j]);
				if(u!=1&&u!=a[i]){
					w[++wt]=(nd){u,1},
					w[++wt]=(nd){a[i]/u,1};
					goto ok;
				}
			}
			for(int j=i+1;j<=n;j++)
				if(a[i]==a[j])goto ok;
			for(int j=1;j<i;j++)
				if(a[j]==a[i])z++;
//			printf("%d!!\n",z);
			ans=1ll*(z+1)*(z+1)*ans%md;
			ok:;
		}
	}
	sort(w+1,w+wt+1);
	for(int i=1;i<=wt;){
		int j=i,z=w[i].z;
		while(j<wt&&w[j+1].a==w[i].a)
			z+=w[++j].z;
//		printf("%d %d %d\n",i,j,ans);
		ans=1ll*(z+1)*ans%md;
		i=j+1;
	}
	printf("%d\n",ans);	
}