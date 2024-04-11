#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int t;
ll x, y, a, b;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%lld %lld %lld %lld",&x,&y,&a,&b);
		if((y - x) % (a + b)){
			puts("-1");
			continue;
		}
		printf("%lld\n",(y - x) / (a + b));
	}
}