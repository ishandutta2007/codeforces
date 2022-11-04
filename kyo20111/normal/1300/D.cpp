#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll x[100100], y[100100];


ll dist(int a,int b){
	return (x[a]-x[b])*(x[a]-x[b]) + (y[a]-y[b])*(y[a]-y[b]);
}

ll cross(int a,int b,int c){
	return x[a]*y[b]+x[b]*y[c]+x[c]*y[a] -y[a]*x[b]-y[b]*x[c]-y[c]*x[a];
}

int main(){
	scanf("%d",&n);
	if(n % 2) return !printf("No");
	for(int i=1;i<=n;i++) scanf("%lld %lld",x+i,y+i);

	for(int i=1;i<=n/2;i++){
		int j = i + n/2;
		if(dist(i, i+1) != dist(j, j%n+1) || cross(i, i+1, (i%n+1)%n+1) != cross(j, j%n+1, (j%n+1)%n+1)) return !printf("No");
	}

	printf("Yes");
}