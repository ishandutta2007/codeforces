#include<stdio.h>
#define ran 1111111
int n,a[ran];
int L[ran],R[ran];
int st[ran],top;
long long int calc(){
	top = 0;
	for(int i=0; i<n; i++){
		while(top > 0 && a[i] > a[st[top-1]])
			top--;
		L[i] = top == 0 ? 0 : st[top-1] + 1;
		st[top++] = i;
	}
	top = 0;
	for(int i=n-1; i>=0; i--){
		while(top > 0 && a[i] >= a[st[top-1]])
			top--;
		R[i] = top == 0 ? n-1 : st[top-1] - 1;
		st[top++] = i;
	}
	long long int res = 0;
	for(int i=0; i<n; i++){
	//	printf("%d %d\n",L[i],R[i]);
		res += (i-L[i]+1LL) * (R[i] - i+1LL) * a[i];
	}
	return res;
}
int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++)
		scanf("%d",&a[i]);
	long long int res = calc();
	for(int i=0; i<n; i++)
		a[i] = -a[i];
	res += calc();
	printf("%I64d\n",res);
	return 0;
}