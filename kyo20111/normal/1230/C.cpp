#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,x[100],y[100],c[10],chk[10][10];
int f(int a){
	int re = 0;
	if(a > n){
		for(int i=1;i<=m;i++) if(++chk[min(c[x[i]],c[y[i]])][max(c[x[i]],c[y[i]])] == 1)re++;
		for(int i=1;i<=6;i++) for(int j=1;j<=6;j++) chk[i][j] = 0;
	}
	else{
		for(int i=1;i<=6;i++){
			c[a] = i;
			re = max(re, f(a+1));
		}
	}
	return re;
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++) scanf("%d %d",&x[i],&y[i]);
	for(int i=1;i<=m;i++) if(x[i] > y[i]) swap(x[i], y[i]);
	printf("%d",f(1));
}