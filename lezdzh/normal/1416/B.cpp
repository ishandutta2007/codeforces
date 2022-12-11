#include<cstdio>
#include<algorithm>
using namespace std;

long long a[10001];
struct da{int i,j,x;};
da ans[100001];
int anst;
int c[10001];
bool cmp(int u,int v){
	return u-a[u]<v-a[v];
}
int main(){
	int t;
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++){
		int n;
		scanf("%d",&n);
		long long sum=0;
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			sum+=a[i];
		}
		if(sum%n){
			printf("-1\n");
			continue;
		}
		sum/=n;
		anst=0;
		for(int i=2;i<=n;i++)
			if(a[i]%i!=0&&a[1]>=i*(a[i]/i+1)-a[i]){
				ans[++anst]=(da){1,i,(int)(i*(a[i]/i+1)-a[i])};
				ans[++anst]=(da){i,1,(int)(a[i]/i+1)};
				a[1]+=a[i];
				a[i]=0;
			}
		for(int i=n;i>1;i--){
			int o=a[i]/i;
			if(o)ans[++anst]=(da){i,1,o};
			a[i]-=i*o;
			a[1]+=i*o;
		}
		c[0]=0;
		for(int i=2;i<=n;i++)
			if(a[i]%i!=0&&a[1]>=i*(a[i]/i+1)-a[i]){
				ans[++anst]=(da){1,i,(int)(i*(a[i]/i+1)-a[i])};
				ans[++anst]=(da){i,1,(int)(a[i]/i+1)};
				a[1]+=a[i];
				a[i]=0;
			}
		c[0]=0;
		for(int i=2;i<=n;i++)
			if(a[i]>sum)c[++c[0]]=i;
		sort(c+1,c+c[0]+1,cmp);
		for(int i=1;i<=c[0];i++)
			if(sum+i-a[c[i]]<=a[1]){
				ans[++anst]=(da){1,c[i],(int)(sum+c[i]-a[c[i]])};
				ans[++anst]=(da){c[i],1,1};
				a[1]+=a[c[i]]-sum;
			}
			else goto ed;
		for(int i=n;i>1;i--)
			if(a[i]<sum)
				ans[++anst]=(da){1,i,(int)(sum-a[i])};
		printf("%d\n",anst);
		for(int i=1;i<=anst;i++)
			printf("%d %d %d\n",ans[i].i,ans[i].j,ans[i].x);
		continue;
		ed:;
		printf("-1\n");
	}
}