#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#define MP make_pair

using namespace std;

typedef long long LL;
typedef long double LD;
typedef vector<int,int> VII;
const LD Eps = 1e-8;


int n, m;
int x[1000005], y[1000005];


//
int U[2000005];
int T[1<<22];
int Base;
void maketree(int siz){
	Base = 1;
	while(Base < siz) Base *= 2;
	//printf("Base=%d\n", Base);
	
	fill(T, T+Base*2, 0);
}
void add(int p, int v){
	p += Base;
	while(p){
		T[p] += v;
		p /= 2;
	}
}
int get(int num, int v, int L, int R){
	//printf("get(%d,%d,%d,%d): %d\n",num,v,L,R, T[v]);
	if(L == R)
		return v-Base;
	
	
	int mid = (L+R)/2;
	if(T[v*2] >= num){
		return get(num, v*2, L, mid);
	} else {
		return get(num-T[v*2], v*2+1, mid+1, R);
	}
}
int get(int num){
	return get(num, 1, 0, Base-1);
}
//

void input(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++){
		scanf("%d%d", &x[i], &y[i]);
	}
}


int res[1000005];
bool found[1000005];

int main(){
	input();
	
	fill(res, res+n, -1);
	fill(found, found+n+1, false);
	
	maketree(n+m);
	for(int i = 0; i < n; i++){
		add(m+i, 1);
	}
	
	for(int i = 0; i < m; i++){
		int pos = get(y[i]), newpos = m-i-1;
		//printf("pos=%d\n", pos);
		if(pos >= m){
			add(pos, -1);
			add(newpos, 1);
			//printf("pos-m=%d x=%d\n", pos-m, x[i]);
			U[newpos] = x[i];
			res[pos-m] = x[i];
			if(found[x[i]]){
				printf("-1\n"); return 0;
			}
			found[x[i]] = true;
		} else {
			if(U[pos] != x[i]){
				printf("-1\n"); return 0;
			}
			add(pos, -1);
			add(newpos, 1);
			U[newpos] = x[i];
		}
	}
	
	int ptr = 1;
	for(int i = 0; i < n; i++){
		if(res[i] == -1){
			while(found[ptr]) ptr++;
			found[ptr] = true;
			res[i] = ptr;
		}
		printf("%d ", res[i]);
	}
	printf("\n");
}