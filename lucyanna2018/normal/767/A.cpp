#include<bits/stdc++.h>
int n,m;
bool a[111111];
int main(){
	scanf("%d",&n);
	m = n;
	for(int i=1; i<=n; i++){
		int x;
		scanf("%d",&x);
		a[x] = true;
		bool isFirst = true;
		while(a[m]){
			if(!isFirst)printf(" ");
			printf("%d",m);
			m--;
			isFirst = false;
		}
		puts("");
	}
	return 0;
}