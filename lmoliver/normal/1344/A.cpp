#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=200200;
int a[N];
int cnt[N];

int md(LL a,LL b){
	if(a>=0){
		return a%b;
	}
	else{
		return (a+((-a)/b+100)*b)%b;
	}
}

void work(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		cnt[i]=0;
	}
	for(int i=0;i<n;i++){
		cnt[md(i+a[i],n)]++;
	}
	bool ok=true;
	for(int i=0;i<n;i++){
		ok&=cnt[i]==1;
	}
	puts(ok?"YES":"NO");
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		work();
	}
	return 0;
}