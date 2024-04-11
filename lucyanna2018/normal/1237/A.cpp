#include<bits/stdc++.h>
using namespace std;
int n,cnt,a[23456];
int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%d",&a[i]);
		if(a[i] % 2)cnt ++;
	}
	cnt /= 2;
	for(int i=0; i<n; i++){
		if(a[i] % 2){
			if(cnt > 0) a[i] ++, cnt --; else
				a[i] --;
		}
		printf("%d\n",a[i] / 2);
	}
	return 0;
}