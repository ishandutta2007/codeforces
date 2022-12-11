#include<cstdio>
#include<algorithm>
using namespace std;

int a[300001],l[300001],r[300001];
int main(){
	int t;
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			l[i]=n+1;
			r[i]=0;
		}
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			l[a[i]]=min(l[a[i]],i);
			r[a[i]]=max(r[a[i]],i);
		}
		sort(a+1,a+n+1);
		a[0]=unique(a+1,a+n+1)-a-1;
		int ans=0;
		for(int i=1;i<=a[0];i++){
			int j=i;
			while(j<a[0]&&l[a[j+1]]>=r[a[j]])
				j++;
			ans=max(ans,j-i+1);
			i=j;
		}
		printf("%d\n",a[0]-ans);
	}
}