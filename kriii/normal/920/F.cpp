#include <stdio.h>
#include <algorithm>
#include <set>
using namespace std;

int N,M,D[1000001],A[300001]; long long B[300001];

void in(int x, int p)
{
	while (x <= N){
		B[x] += p;
		x += x & (-x);
	}
}

long long out(int x)
{
	long long r = 0;
	while (x){
		r += B[x];
		x -= x & (-x);
	}
	return r;
}

int main()
{
	for (int i=1;i<=1000000;i++) for (int j=i;j<=1000000;j+=i) D[j]++;

	scanf ("%d %d",&N,&M);
	set<int> pos;
	for (int i=1;i<=N;i++){
		scanf ("%d",&A[i]);
		in(i,A[i]);
		if (A[i] > 2) pos.insert(i);
	}

	for (int q=1;q<=M;q++){
		int o,l,r; scanf ("%d %d %d",&o,&l,&r);
		if (o == 1){
			auto I = pos.lower_bound(l);
			while (I != pos.end() && *I <= r){
				int i = *I, last = A[i], nxt = D[A[i]];
				in(i,nxt-last);
				A[i] = nxt;
				if (nxt <= 2) I = pos.erase(I);
				else I++;
			}
		}
		else{
			printf ("%lld\n",out(r)-out(l-1));
		}
	}
	return 0;
}