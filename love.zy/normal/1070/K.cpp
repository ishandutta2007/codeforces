#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;
int n,k,a[MAXN];
vector<int> b;

int main()
{
	int i,s=0;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s+=a[i];
	}
	if(s%k){
		printf("No\n");
		return 0;
	}
	a[n+1]=0;
	int t=s/k;
	s=0;
	int pre=0;
	for(i=1;i<=n+1;i++){
		s+=a[i];
		if(s>t){
			printf("No\n");
			return 0;
		}
		if(s==t){
			b.push_back(i-pre);
			s=0;
			pre=i;
		}
	}
	if(s||b.size()!=k){
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	for(i=0;i<k-1;i++) printf("%d ",b[i]);
	printf("%d\n",b[i]);
 return 0;
}