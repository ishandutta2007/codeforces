#include<cstdio>
#include<algorithm>
using namespace std;
const int N=10002;
struct p{
	int id,k;
}a[N];
int n,i,j,l[N],r[N],val[N],s;
bool cmp(p x,p y){
	return x.k<y.k;
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",l+i);
	for(i=1;i<=n;i++){
		scanf("%d",r+i);		
		a[i].id=i;
		a[i].k=l[i]+r[i];
	}
	sort(a+1,a+n+1,cmp);
	val[0]=n;
	for(i=1;i<=n;i++)
		val[a[i].id]=val[a[i-1].id]-(a[i].k!=a[i-1].k);

	for(i=1;i<=n;i++){
		s=0;
		for(j=1;j<i;j++)
			if(val[j]>val[i])
				s++;
		if(s!=l[i]){
			printf("NO");
			return 0;
		}
		s=0;
		for(j=i+1;j<=n;j++)
			if(val[j]>val[i])
				s++;
		if(s!=r[i]){
			printf("NO");
			return 0;
		}				
	}
	printf("YES\n");
	for(i=1;i<=n;i++)
		printf("%d ",val[i]);
}