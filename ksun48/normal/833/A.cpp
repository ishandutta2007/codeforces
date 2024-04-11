#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int a1, b1;
		scanf("%d%d", &a1, &b1);
		LL a, b;
		a = a1;
		b = b1;
		LL r = a*b;
		LL s = 0;
		LL e = 1e6 + 1;
		while(s+1 < e){
			LL m = (s+e)/2;
			if(m*m*m <= r){
				s = m;
			} else {
				e = m;
			}
		}
		if(s*s*s == r && (a % s == 0) && (b % s == 0)){
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
}