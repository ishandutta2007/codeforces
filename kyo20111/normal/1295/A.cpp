#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t, n;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		if(n & 1) printf("7"), n-=3;
		while(n){
			printf("1");
			n -= 2;
		}
		puts("");
	}
}