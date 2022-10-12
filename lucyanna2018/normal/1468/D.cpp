#include<bits/stdc++.h>
using namespace std;
int n,a[222222];
int main(){
	int _,X1,X2,X3,A,B;
	for(scanf("%d",&_); _--;){
		scanf("%d%d%d%d",&X1,&n,&X2,&X3);
		if(X2 < X3){
			A = X3 - X2;
			B = X2 - 1;
		}else{
			A = X2 - X3;
			B = X1 - X2;
		}
		B += A;
		A --;
		for(int i=0; i<n; i++)
			scanf("%d",&a[i]);
		sort(a,a+n);
		int res = 0, pnt = n;
		for(int i=1; i<=A; i++){
			pnt --;
			while(pnt >= 0 && a[pnt] + i > B)pnt --;
			if(pnt < 0)break;
			res ++;
		}
		printf("%d\n",res);
	}
	return 0;
}