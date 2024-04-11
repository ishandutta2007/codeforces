#include<bits/stdc++.h>
using namespace std;
int n,a[111111];
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
int calc(int x){
	if(x%2==0)return x/2;
	return x/2+2;
}
int main(){
	scanf("%d",&n);
	int g=0;
	for(int i=0; i<n; i++){
		scanf("%d",&a[i]);
		g=gcd(g,a[i]);
	}
	puts("YES");
	if(g > 1){
		puts("0");
		return 0;
	}
	int step = 0, cnt = 0;
	for(int i=0; i<n; i++)
		if(a[i]%2==0){
			step += calc(cnt);
			cnt=0;
		}else
			cnt++;
	step += calc(cnt);
	printf("%d\n",step);
	return 0;
}