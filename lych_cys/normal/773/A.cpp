#include<bits/stdc++.h>
using namespace std;

int calc(int x,int y){
	if (!x) return 0; else return (x-1)/y+1;
}
int gcd(int x,int y){ return y?gcd(y,x%y):x; }
int main(){
	int cas; scanf("%d",&cas);
	while (cas--){
		int x,y,p,q;
		scanf("%d%d%d%d",&x,&y,&p,&q);
		int w=gcd(p,q); p/=w; q/=w;
		if (p==q && x<y) puts("-1"); else
		if (!p && x>0) puts("-1"); else{
			int tmp=max(max(calc(x,p),calc(y,q)),calc(y-x,q-p));
			printf("%lld\n",(long long)tmp*q-y);
		}
	}
	return 0;
}