#include<bits/stdc++.h>
int a[22],n,k;
int fnd(int n){
	for(int i=2; i*i<=n; i++)
		if(n%i==0)
			return i;
	return n;
}
bool proc(int k){
	while(--k){
		if(n == 1)return false;
		int x = fnd(n);
		n /= x;
		a[k] = x;
	}
	a[0] = n;
	return n>1;
}
int main(){
	scanf("%d%d",&n,&k);
	if(!proc(k))puts("-1");else
		for(int i=0; i<k; i++)
			printf("%d%c",a[i],i<k-1?' ':'\n');
	return 0;
}