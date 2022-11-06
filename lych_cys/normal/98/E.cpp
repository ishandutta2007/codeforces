#include <bits/stdc++.h>
#define ll long long
using namespace std;

int m,n; double g[1005][1005];
double f(int x,int y){
	if (!x) return 1.0/(y+1); if (!y) return 1.0;
	if (g[x][y]) return g[x][y];
	double a=1.0,b=1-f(y,x-1),c=(1-f(y-1,x))*y/(y+1),d=(1-f(y-1,x))*y/(y+1)+1.0/(y+1);
	double p=(d-c)/(a-b-c+d);
	return g[x][y]=p*a+(1-p)*c;
}
int main(){
	scanf("%d%d",&m,&n);
	printf("%.10f %.10f\n",f(m,n),1-f(m,n));
	return 0;
}