#include<cstdio>

using namespace std;

int a[1001],b[1001];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	double l=0,r=1e9;
	for(int t=1;t<=100;t++){
		double mid=0.5*(l+r);
		double o=mid+m;
		for(int i=1;i<=n;i++){
			o=o-o/a[i];
			o=o-o/b[i%n+1];
			if(o<m-1e-9)goto ed;
		}
		r=mid;
		continue;
		ed:;
		l=mid;
	}
	if(l>=1e9-1e-7)printf("-1\n");
	else printf("%.10f\n",l);
}