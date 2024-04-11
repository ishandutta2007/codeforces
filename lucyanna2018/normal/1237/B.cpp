#include<bits/stdc++.h>
using namespace std;
int f[123456],a[123456],n;
int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		int x;
		scanf("%d",&x);
		f[x] = i;
	}
	for(int i=0; i<n; i++){
		int x;
		scanf("%d",&x);
		a[i] = f[x];
	}
	int z = n + 1, cnt = 0;
	for(int i=n-1; i>=0; i--){
		if(a[i] < z)z = a[i];else
			cnt ++;
	}
	printf("%d\n",cnt);
	return 0;
}