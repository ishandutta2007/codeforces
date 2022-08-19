#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n;
	int q;
	scanf("%d%d", &n, &q);
	int p0 = 0;
	int p1 = 1;
	for(int i = 0; i < q; i++){
		int c = 0;
		scanf("%d", &c);
		if(c == 1){
			int x;
			scanf("%d", &x);
			p0 += n+x;
			p1 += n+x;
			p0 %= n;
			p1 %= n;
		} else {
			p0 += n;
			p1 += n;
			if(p0 % 2 == 1){
				p0 ++;
			} else {
				p0--;
			}
			if(p1 % 2 == 1){
				p1 ++;
			} else {
				p1--;
			}
			p0 %= n;
			p1 %= n;
		}
	}
	p0 %= n;
	p1 %= n;
	while(p0 < 0) p0 += n;
	while(p1 < 0) p1 += n;
	int stuff[n];
	for(int i = 1; i <= n; i++){
		if(i % 2 == 0) stuff[(i+p0+n-1)%n+1] = i;
		if(i % 2 == 1) stuff[(i+p1-1+n-1)%n+1] = i;
	}
	for(int i = 1; i <= n; i++){
		printf("%d ", stuff[i]);
	}
	printf("\n");
}