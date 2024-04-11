#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100002;
int q,n,i,a[N],b[N],tmp;
int main(){
	scanf("%d",&q);
	while(q--){
		scanf("%d",&n);
		tmp=1;
		for(i=1;i<=4*n;i++)
			scanf("%d",a+i);
		sort(a+1,a+4*n+1);
		for(i=1;i<=2*n;i++)
			if(a[i*2-1]!=a[i*2])
				tmp=0;
			else
				b[i]=a[i*2];
		for(i=1;i<n;i++)
			if(b[i]*b[2*n-i+1]!=b[i+1]*b[2*n-i])
				tmp=0;
		printf("%s\n",tmp?"YES":"NO");
	}
}