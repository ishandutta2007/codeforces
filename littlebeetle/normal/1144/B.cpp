#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1000002;
int n,p,q,a,i,x[N],y[N];
bool cmp(int x,int y){
	return x>y;
}
long long ans;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a);
		if(a&1)
			x[++p]=a;
		else
			y[++q]=a;
	}
	sort(x+1,x+p+1,cmp);
	sort(y+1,y+q+1,cmp);
	if(p==q||p==q+1||q==p+1){
		printf("0");
		return 0;
	}
	if(p>q){
		for(i=q+2;i<=p;i++)
			ans+=x[i];
		printf("%I64d",ans);
	}
	else{
		for(i=p+2;i<=q;i++)
			ans+=y[i];
		printf("%I64d",ans);
	}
}