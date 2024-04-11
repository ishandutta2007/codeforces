#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

const int N=1<<21;
int st[2*N];

void add(int x){
	for (x+=N;x;x/=2){
		st[x]++;
	}
}

int sum(int a, int b){
	a+=N;
	b+=N;
	int s=0;
	while (a<=b){
		if (a%2) s+=st[a++];
		if (!(b%2)) s+=st[b--];
		a/=2;
		b/=2;
	}
	return s;
}

int main(){
	int n,k;
	scanf("%d %d", &n, &k);
	if (k>n/2){
		k=n-k;
	}
	int x=0;
	ll v=1;
	for (int i=0;i<n;i++){
		int s=sum(x+1, x+k-1);
		v+=(ll)(s+1);
		add(x);
		add(x+n);
		add((x+k)%n);
		add((x+k)%n+n);
		x=(x+k)%n;
		printf("%lld\n", v);
	}
}