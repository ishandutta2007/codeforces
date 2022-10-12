#include<bits/stdc++.h>
using namespace std;
const int ran = 1000010;
int n,a[ran];

typedef unsigned int uint;
typedef unsigned long long int uint64;
inline uint xrand(void) {
    static uint x = 123456789;
    static uint y = 362436069;
    static uint z = 521288629;
    static uint w = 88675123;
    uint t;
    t = x ^ (x << 11); x = y; y = z; z = w;
    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
}
inline uint randrange(uint n) {
    return (uint64(xrand()) * n) >> 32;
}

#define i64 long long int
int bit[ran];
int lowbit(int x){return x&-x;}
void add(int x){
	while(x<=n){
		bit[x]++;
		x+=lowbit(x);
	}
}
int query(int x){
	int r=0;
	while(x){
		r+=bit[x];
		x-=lowbit(x);
	}
	return r;
}
i64 calc(){
	i64 res=0;
	memset(bit,0,sizeof(bit));
	for(int i=1; i<=n; i++){
		res += query(a[i]);
		add(a[i]);
	}
	return res%2;
}

int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++)a[i] = i;
	for(int i=1; i<=3*n; i++){
		int x,y;
		while(1){
			x = xrand()%n+1;
			y = xrand()%n+1;
			if(x!=y)break;
		}
		swap(a[x],a[y]);
	}
	i64 A = calc();

	for(int i=1; i<=n; i++)a[i] = i;
	for(int i=1; i<=7*n+1; i++){
		int x,y;
		while(1){
			x = xrand()%n+1;
			y = xrand()%n+1;
			if(x!=y)break;
		}
		swap(a[x],a[y]);
	}
	i64 B = calc();

	for(int i=1; i<=n; i++)scanf("%d",&a[i]);
	i64 C = calc();
	puts(A==C ? "Petr" : "Um_nik");
	return 0;
}