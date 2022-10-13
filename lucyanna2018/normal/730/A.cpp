#include<stdio.h>
#include<algorithm>
using namespace std;
int n,lo,id[111],a[111];
char o[11111][111];
bool cmp(int x,int y){
	return a[x] < a[y];
}
int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++)
		scanf("%d",&a[i]);
	while(1){
		for(int i=0; i<n; i++)
			id[i] = i;
		sort(id,id+n,cmp);
		int small = a[id[0]], large = a[id[n-1]];
		if(small == large){
			break;
		}
		++lo;
		for(int i=0; i<n; i++)
			o[lo-1][i] = '0';
		o[lo-1][n]=0;
		if(small == large-1 && n >= 3 && large == a[id[n-2]] && a[id[n-3]] == large && (n < 4 || a[id[n-4]] != large)){
			o[lo-1][id[n-1]] = '1';
			o[lo-1][id[n-2]] = '1';
			o[lo-1][id[n-3]] = '1';
			if(a[id[n-1]] != 0)a[id[n-1]] --;
			if(a[id[n-2]] != 0)a[id[n-2]] --;
			if(a[id[n-3]] != 0)a[id[n-3]] --;
			break;
		}else{
			o[lo-1][id[n-1]] = '1';
			o[lo-1][id[n-2]] = '1';
			if(a[id[n-1]] != 0)a[id[n-1]] --;
			if(a[id[n-2]] != 0)a[id[n-2]] --;
		}
	}
	printf("%d\n",a[0]);
	printf("%d\n",lo);
	for(int i=0; i<lo; i++)
		puts(o[i]);
	return 0;
}