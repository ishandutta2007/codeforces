#include<cstdio>
#include<algorithm>
using namespace std;

int a[100001];
int b[32];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		for(int j=0;j<=30;j++)
			b[j]+=a[i]>>j&1;
	}
	int mx=-1,o=0;
	for(int i=1;i<=n;i++){
		int s=0;
		for(int j=0;j<=30;j++)
			if(a[i]>>j&1&&b[j]==1)
				s+=1<<j;
		if(s>mx)mx=s,o=i;
	}
	printf("%d",a[o]);
	for(int i=1;i<=n;i++)
		if(i!=o)printf(" %d",a[i]);
	printf("\n");
}