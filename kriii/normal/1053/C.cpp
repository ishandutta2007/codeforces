#include <stdio.h>

const int Z = 1<<18;
const long long mod = 1000000007;
struct node{
	node(){
		a = w = s = 0;
	}
	node(long long a_, long long w_){
		a = a_;
		w = w_;
		s = a * w % mod;
	}
	node(long long a_, long long w_, long long s_){
		a = a_;
		w = w_;
		s = s_;
	}
	long long a,w,s;

	node operator +(const node &t)const{
		return {a + t.a, w + t.w, (s + t.s) % mod};
	}
}IT[Z*2];

int N,Q,A[200200],W[200200];

void push(int x)
{
	IT[x+Z] = node(A[x],W[x]);
	x = (x + Z) / 2;
	while (x){
		IT[x] = IT[x*2] + IT[x*2+1];
		x /= 2;
	}
}

node get(int x, int y)
{
	node r;
	x += Z; y += Z;
	while (x < y){
		if (x & 1) r = r + IT[x++];
		if (y & 1) r = r + IT[--y];
		x /= 2; y /= 2;
	}
	return r;
}

int getPos(long long w)
{
	int x = 1;
	while (x < Z){
		x *= 2;
		if (w > IT[x].w){
			w -= IT[x].w;
			x++;
		}
	}
	return x - Z;
}

int main()
{
	scanf ("%d %d",&N,&Q);
	for (int i=1;i<=N;i++) scanf ("%d",&A[i]), A[i] -= i;
	for (int i=1;i<=N;i++) scanf ("%d",&W[i]);
	for (int i=1;i<=N;i++) IT[i+Z] = node(A[i],W[i]);
	for (int i=Z-1;i>=1;i--) IT[i] = IT[i*2] + IT[i*2+1];

	while (Q--){
		int x,y; scanf ("%d %d",&x,&y);
		if (x < 0){
			W[-x] = y;
			push(-x);
		}
		else{
			y++;
			node s = get(x,y);
			node l = get(0,x);

			long long want = l.w + (s.w + 1) / 2;
			int p = getPos(want);
			long long c = A[p];

			node a = get(x,p);
			node b = get(p+1,y);

			long long as = (a.w % mod * c) + mod - a.s;
			long long bs = b.s + mod - (b.w % mod * c) % mod;
			printf ("%lld\n",(as + bs) % mod);
		}
	}
	return 0;
}