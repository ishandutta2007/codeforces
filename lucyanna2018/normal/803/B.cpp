#include<bits/stdc++.h>
using namespace std;
int n;
bool f[222222];
int r[222222];
const int inf  = 9999999;
int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		int x;
		scanf("%d",&x);
		f[i] = (x==0);
		r[i] = inf;
	}
	int d = inf;
	for(int i=1; i<=n; i++){
		if(f[i])d=0;else
			d++;
		r[i] = min(r[i], d);
	}
	d = inf;
	for(int i=n; i>=1; i--){
		if(f[i])d=0;else
			d++;
		r[i] = min(r[i],d);
	}
	for(int i=1; i<=n; i++)
		printf("%d%c",r[i],i<n?' ':'\n');
	return 0;
}