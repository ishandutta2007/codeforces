#include<bits/stdc++.h>
using namespace std;
int n,a[222222];
int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	int bes = 2147483647, num = 0;
	for(int i=1; i<n; i++)
		if(a[i] - a[i-1] < bes){
			bes = a[i] - a[i-1];
			num = 1;
		}else
		if(a[i] - a[i-1] == bes)
			num++;
	printf("%d %d\n",bes,num);
	return 0;
}