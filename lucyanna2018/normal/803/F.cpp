#include<bits/stdc++.h>
using namespace std;
const int MAX = 100000;
int a[MAX + 1],p[MAX + 1];
int cnt[MAX + 1];
int mul[MAX + 1];

#define mod 1000000007
int add(int x,int y){
	return (x+=y)<mod?x:x-mod;
}
int sub(int x,int y){
	return add(x,mod-y);
}

int main(){
	int n,x;
	for(scanf("%d",&n); n--;){
		scanf("%d",&x);
		cnt[x]++;
	}
	for(int i=1; i<=MAX; i++)
	for(int j=i; j<=MAX; j+=i)
		mul[i] += cnt[j];
	p[0] = 0;
	for(int i=1; i<=MAX; i++)
		p[i] = add(add(p[i-1],p[i-1]),1);
	for(int i=MAX; i>=1; i--){
		a[i] = p[mul[i]];
		for(int j=i+i; j<=MAX; j+=i)
			a[i] = sub(a[i], a[j]);
	}
	printf("%d\n",a[1]);
	return 0;
}