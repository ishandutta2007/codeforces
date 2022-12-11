#include<cstdio>
#include<algorithm>
using namespace std;

int a[100001];
int main(){
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int p=1;while(a[p]<0)p++;
	int a1=1e9,a2=-1e9,s=0;
	for(int i=p;i<=n;i++)if(a[i]&1){a1=a[i];break;}
	for(int i=p-1;i;i--)if(a[i]&1){a2=a[i];break;}
	for(int i=p;i<=n;i++)s+=a[i];
	if(s&1)printf("%d",s);
	else printf("%d",max(s-a1,s+a2));
}