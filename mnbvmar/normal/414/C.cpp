#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string.h>
#include <string>

using namespace std;

const int MaxN = 21,
          MaxS = 1050005;

int n, m;
int a[MaxS];

void input(){
	scanf("%d", &n);
	for(int i = 0; i < (1<<n); i++)
		scanf("%d", &a[i]);
	
	scanf("%d", &m);
}


typedef long long LL;

LL inva[MaxS*2], invb[MaxS*2], invsame[MaxS*2];
LL invlvla[MaxN], invlvlsum[MaxN];
bool rev[MaxN];

int cpya[MaxS], cpyb[MaxS];

void getinv(int L, int R, int pos){
	if(L==R) return;
	if(R-L == 1){
		inva[pos] = invb[pos] = 0;
		return;
	}
	
	int mid = (L+R)/2, siz = mid-L;
	getinv(L, mid, pos*2);
	getinv(mid, R, pos*2+1);
	
	copy(a+L, a+mid, cpya);
	copy(a+mid, a+R, cpyb);
	cpya[mid-L] = 1010101010;
	cpyb[R-mid] = 1010101010;
	
	LL suma = 0, sumb = 0;
	
	int ptrl = 0, ptrr = 0, ptr=L;
	while(ptrl < siz || ptrr < siz){
		if(cpya[ptrl] <= cpyb[ptrr]){
			//printf("A\n");
			a[ptr++] = cpya[ptrl++];
			suma += ptrr;
		} else {// if(cpya[ptrl] > cpyb[ptrr]){
			//printf("B\n");
			a[ptr++] = cpyb[ptrr++];
			//sumb += ptrl;
		}
	}
	
	inva[pos] = suma;
	
	int last = L-1, val=-1;
	for(int i = L; i < R; i++){
		if(a[i] == val){
			invsame[pos] += i-last;
		} else {
			last = i; val = a[i];
		}
	}
}

LL query(){
	int q;
	scanf("%d", &q);
	
	q = n-q;
	
	rev[q] = !rev[q];
	
	LL res = 0;
	for(int i = n; i >= 0; i--){
		res += invlvla[i];
		if(rev[i])
			res = invlvlsum[i] - res;
	}
	return res;
}


int main(){
	input();
	
	if(n == 0){
		for(int i = 0; i < m; i++) printf("0\n");
		return 0;
	}
	
	getinv(0, 1<<n, 1);
	
	for(int i = 0; i <= n; i++){
		for(int j = (1<<i); j < (1<<(i+1)); j++){
			invlvla[i] += inva[j];
			LL siz = (1<<(n-i));
			invlvlsum[i] += siz*(siz-1)/2 - invsame[j];
		}
	}
	
	while(m--)
		printf("%I64d\n", query());
}