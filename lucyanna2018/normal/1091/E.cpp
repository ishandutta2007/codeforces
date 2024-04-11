#include<bits/stdc++.h>
using namespace std;
#define ran 500050
int n,b[ran],a[ran];
int chk(int x){
	for(int i=1; i<n; i++)a[i] = b[i];a[n] = x;
	sort(a+1,a+n+1);reverse(a+1,a+n+1);
	int id=-1;
	for(int i=1; i<=n; i++)if(a[i] == x){
		id = i;
		break;
	}
	long long int sum = 0, sum2 = 0;
	int pnt = n;
	for(int i=1; i<=n; i++){
		sum += a[i];
		while(pnt < i){
			pnt++;
			sum2 -= a[pnt];
		}
		while(pnt > i && a[pnt]<i){
			sum2 += a[pnt];
			pnt--;
		}
		if(sum > sum2 + (pnt-1LL)*i)
			return id<=i ? 1 : -1;
	}
	return 0;
}
int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++)scanf("%d",&b[i]);
	int M = 0;for(int i=1; i<=n; i++)M^=b[i]%2;
	int lo = M, hi = n;while(hi % 2 != M)hi --;
	++n;
	if(chk(lo) == 1 || chk(hi) == -1){
		puts("-1");
		return 0;
	}
	int L = lo, R = hi;
	while(L != R){
		int mi = (L+R)/2;if(mi % 2 != M)mi--;
		if(chk(mi) == -1)L = mi+2;else
			R = mi;
	}
	int S = L;
	L = lo, R = hi;
	while(L != R){
		int mi = (L+R)/2;if(mi % 2 != M)mi++;
		if(chk(mi) == 1)R = mi-2;else
			L = mi;
	}
	int E = L;
	if(chk(S) == 0 && chk(E) == 0){
		for(int i=S; i<E; i+=2)printf("%d ",i);
		printf("%d\n",E);
	}else
		puts("-1");
	return 0;
}