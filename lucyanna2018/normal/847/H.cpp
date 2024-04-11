#include<stdio.h>
#include<algorithm>
using namespace std;
#define ran 111111
int n,a[ran];
long long int tot_l[ran],val_l[ran];
long long int tot_r[ran],val_r[ran];
int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%d",&a[i]);
	for(int i=1; i<=n; i++){
		val_l[i] = max(val_l[i-1]+1, (long long int)a[i]);
		tot_l[i] = tot_l[i-1] + val_l[i] - a[i];
	}
	for(int i=n; i>=1; i--){
		val_r[i] = max(val_r[i+1]+1, (long long int)a[i]);
		tot_r[i] = tot_r[i+1] + val_r[i] - a[i];
	}
	long long int res = (long long int)(1e18);
	for(int i=1; i<=n; i++){
		res = min(res, tot_l[i-1] + tot_r[i+1] + max(val_l[i],val_r[i]) - a[i]);
	}
	printf("%I64d\n",res);
	return 0;
}