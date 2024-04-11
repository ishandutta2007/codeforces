#include<stdio.h>
#include<algorithm>
using namespace std;
#define Z 2048

int N,Q;
int a[200010];
int bit[102][200010];

int add(int x,int y){
	return x+y;
}
int sub(int x,int y){
	return x-y;
}

int lowbit(int x){return x&-x;}
void inc(int*bit,int x,int y){
	while(x<=N){
		bit[x]=add(bit[x],y);
		x+=lowbit(x);
	}
}
void dec(int*bit,int x,int y){
	while(x<=N){
		bit[x]=sub(bit[x],y);
		x+=lowbit(x);
	}
}
int query(int*bit,int x){
	int r=0;
	while(x){
		r=add(r,bit[x]);
		x-=lowbit(x);
	}
	return r;
}
int ask2(int from,int to,int lo,int hi){
	int F = from/Z, T = to/Z, res = 0;
	if(F==T){
		for(int i=from; i<=to; i++)
			if(lo < a[i] && a[i] < hi)
				++res;
		return res;
	}
	for(int i=from; i<(F+1)*Z; i++)
		if(lo < a[i] && a[i] < hi)
			++res;
	for(int i=T*Z; i<=to; i++)
		if(lo < a[i] && a[i] < hi)
			++res;
	for(int i=F+1; i<T; i++)
		res = add(res, sub(query(bit[i],hi),query(bit[i],lo)));
	return res;
}

int main(){
	scanf("%d%d",&N,&Q);
	long long int now = 0;
	for(int i=0; i<N; i++){
		a[i] = i+1;
		inc(bit[i/Z], a[i], 1);
	}
	while(Q--){
		int x,y;
		scanf("%d%d",&x,&y);
		--x;--y;
		if(x==y){
			printf("%I64d\n",now);
			continue;
		}
		if(x>y)swap(x,y);

		if(a[x] > a[y]){
			--now;
			now -= 2*ask2(x+1, y-1, a[y], a[x]);
		}else{
			++now;
			now += 2*ask2(x+1, y-1, a[x], a[y]);
		}
		dec(bit[x/Z], a[x], 1);
		dec(bit[y/Z], a[y], 1);
		swap(a[x],a[y]);
		inc(bit[x/Z], a[x], 1);
		inc(bit[y/Z], a[y], 1);
		printf("%I64d\n",now);
	}
	return 0;
}