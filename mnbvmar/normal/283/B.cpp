#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <math.h>
#include <complex>
#include <iostream>

using namespace std;

const int maxN = 200005;

typedef long long LL;

bool used[maxN];
int n;
int tbl[maxN];
LL type[maxN];

LL check(int v){
	//printf("check(%d)\n", v);
	type[v] = -1;
	used[v] = true;
	int x = v+tbl[v];
	int sum = tbl[v];
	if(x > n) return (type[v] = sum);
	
	sum += tbl[x];
	x -= tbl[x];
	//printf("=>%d\n", x);
	if(x < 1) return (type[v] = sum);
	if(x == 1 || x == v) return (type[v] = -1);
	if(used[x]){
		if(type[x] == -1) return (type[v] = -1);
		return (type[v] = (LL)sum + type[x]);
	}
	
	LL wyn = check(x);
	if(wyn == -1) return (type[v] = -1); else return (type[v] = (LL)sum+wyn);
}

int main(){
	scanf("%d", &n);
	for(int i = 2; i <= n; i++) scanf("%d", &tbl[i]);
	
	for(int i = 2; i <= n; i++){
		if(!used[i]){ /*printf("\n");*/ check(i); }
	}
	type[1] = -1;
	//for(int i = 1; i <= n; i++) cout << type[i] << " ";
	//rintf("\n");
	
	for(int i = 1; i < n; i++){
		tbl[1] = i;
		int x=1, y=0;
		y += tbl[x]; x += tbl[x];
		if(x > n){ printf("%d\n", y); continue; }
		y += tbl[x]; x -= tbl[x];
		if(x < 1){ printf("%d\n", y); continue; }
		
		if(type[x] == -1){
			printf("-1\n");
		} else {
			cout << type[x]+y << endl;
			//printf("%I64d\n", type[x]+y);
		}
	}
	
	return 0;
}