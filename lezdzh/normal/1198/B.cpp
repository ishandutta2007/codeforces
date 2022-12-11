#include<cstdio>
#include<algorithm>
using namespace std;

int a[200001];
int b[200001],z[200001];
int w[200002];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int q;
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		int o,p,x;
		scanf("%d",&o);
		if(o==1){
			scanf("%d%d",&p,&x);
			b[p]=i;
			z[p]=x;
		}
		else{
			scanf("%d",&x);
			w[i]=x;
		}
	}
	for(int i=q;i>=0;i--)
		w[i]=max(w[i],w[i+1]);
	for(int i=1;i<=n;i++)
		printf("%d%c",max(b[i]==0?a[i]:z[i],w[b[i]]),i==n?'\n':' ');
}