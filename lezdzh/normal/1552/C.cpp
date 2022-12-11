#include<cstdio>
#include<algorithm>
using namespace std;

int a[201],b[201],l[101],r[101];
int main(){
	int t;
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++){
		int n,k;
		scanf("%d%d",&n,&k);
		int ans=0;
		for(int i=1;i<=2*n;i++)
			a[i]=1;
		for(int i=1;i<=k;i++){
			scanf("%d%d",&l[i],&r[i]);
			a[l[i]]=a[r[i]]=0;
			if(l[i]>r[i])swap(l[i],r[i]);
		}
		b[0]=0;
		for(int i=1;i<=2*n;i++)
			if(a[i])b[++b[0]]=i;
		for(int i=1;i<=b[0]/2;i++)
			l[++k]=b[i],
			r[k]=b[i+b[0]/2];
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if((l[j]>=l[i]&&l[j]<=r[i])!=(r[j]>=l[i]&&r[j]<=r[i]))
					ans++;
		printf("%d\n",ans);
	}
}