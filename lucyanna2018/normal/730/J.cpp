#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int n,m,tot;
pair<int,int> a[111];
int d[111][11111];
void upd(int&x,int y){
	if(x==-1 || x<y)
		x=y;
}
int main(){
	tot = 0;
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i].second);
		tot += a[i].second;
	}
	for(int i=1; i<=n; i++)
		scanf("%d",&a[i].first);
	sort(a+1,a+n+1);
	int tot2 = 0;
	for(int i=n; i>=1; i--){
		++m;
		tot2 += a[i].first;
		if(tot2 >= tot)
			break;
	}
	memset(d,-1,sizeof(d));
	d[0][0] = 0;
	tot2 = 0;
	for(int i=1; i<=n; i++){
		for(int j=min(i,m)-1; j>=0; j--)
		for(int k=tot2; k>=0; k--)
		if(d[j][k] != -1)
			upd(d[j+1][k+a[i].first],d[j][k]+a[i].second);
		tot2 += a[i].first;
	}
	int res=-1;
	for(int i=tot; i<=tot2; i++)
		if(d[m][i]!=-1)
		upd(res, d[m][i]);
	printf("%d %d\n",m,tot-res);
	return 0;
}