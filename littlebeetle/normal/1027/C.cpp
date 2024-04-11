#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1000002;
int T,n,i,a[N],m,b[N],u,v;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",a+i);
		sort(a+1,a+n+1);
		m=0;
		for(i=1;i<n;i++)
			if(a[i]==a[i+1]){
				b[++m]=a[i];
				i++;
			}
		u=1;v=10001;
		for(i=1;i<m;i++)
			if(v*b[i]>u*b[i+1]){
				u=b[i];v=b[i+1];
			}
		printf("%d %d %d %d\n",u,u,v,v);
	}
}