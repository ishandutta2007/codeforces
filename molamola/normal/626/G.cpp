#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <time.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> Pi;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()
typedef pair<double, int> Pd;

int n, t, q;
int now[200020];
int L[200020], P[200020];
double ans;
int ADD = 1<<18;

struct tree{
	Pd T[1<<19 | 5];
	int t;	//t = 0 : MAX, t = 1 : MIN
	void update(double x,int idx){
		T[idx + ADD] = Pd(x, idx);
		idx = (idx + ADD) >> 1;
		while(idx){
			int down = (T[idx<<1].Fi > T[idx<<1|1].Fi) ? (idx<<1) : (idx<<1|1);
			down ^= t;
			T[idx] = T[down];
			idx >>= 1;
		}
	}
}T1, T2;

void Fix2(Pd &x1, Pd &x2){
	ans += x1.Fi - x2.Fi;
	int idx1 = x1.Se;
	int idx2 = x2.Se;
	now[idx1]++;
	now[idx2]--;
	if(now[idx1] < L[idx1])T1.update((double)(P[idx1] * L[idx1]) / (L[idx1] + now[idx1]) / (L[idx1] + now[idx1] + 1), idx1);
	else T1.update(0, idx1);
	T2.update(x1.Fi, idx1);
	
	if(now[idx2] < L[idx2])T1.update(x2.Fi, idx2);
	else T1.update(0, idx2);
	if(now[idx2] > 0)T2.update((double)(P[idx2] * L[idx2]) / (L[idx2] + now[idx2]) / (L[idx2] + now[idx2] - 1), idx2);
	else T2.update(1e7, idx2);
}

void Fix(){
	Pd x1 = T1.T[1];
	Pd x2 = T2.T[1];
	//printf("%f %d, %f %d\n", x1.Fi, x1.Se, x2.Fi, x2.Se);
	if(x1.Fi > x2.Fi)Fix2(x1, x2);
}

int main(){
	T1.t = 0, T2.t = 1;
	for(int i=0;i<1<<19;i++)T2.T[i].Fi = 1e7;
	scanf("%d%d%d", &n, &t, &q);
	for(int i=1;i<=n;i++)scanf("%d", P+i);
	for(int i=1;i<=n;i++)scanf("%d", L+i);
	for(int i=1;i<=n;i++){
		T1.update((double)P[i] / (L[i] + 1), i);
	}
	while(t){
		Pd x = T1.T[1];
		if(x.Fi < 1e-10)break;
		int idx = x.Se;
		ans += x.Fi;
		T2.update(x.Fi, idx);
		now[idx]++;
		if(now[idx] < L[idx])T1.update((double)(P[idx] * L[idx]) / (L[idx] + now[idx]) / (L[idx] + now[idx] + 1), idx);
		else T1.update(0, idx);
		--t;
	}
	
	while(q--){
		int x, y;
		scanf("%d%d", &x, &y);
		if(x == 1){
			ans -= (double)(now[y] * P[y]) / (L[y] + now[y]) / (L[y] + now[y] + 1);
			L[y]++;
			
			if(t > 0){
				--t;
				double tmp = (double)(L[y] * P[y]) / (L[y] + now[y]) / (L[y] + now[y] + 1);
				ans += tmp;
				T2.update(tmp, y);
				T1.update(0, y);
				now[y]++;
			}
			
			else{
				T1.update((double)(P[y] * L[y]) / (L[y] + now[y]) / (L[y] + now[y] + 1), y);
				if(now[y] > 0)T2.update((double)(P[y] * L[y]) / (L[y] + now[y]) / (L[y] + now[y] - 1), y);
			
				Fix();
			}
		}
		else{
			ans += (double)(now[y] * P[y]) / (L[y] + now[y]) / (L[y] + now[y] - 1);
			L[y]--;
			
			if(now[y] > L[y]){
				if(T1.T[1].Fi < 1e-10){
					t++;
					now[y]--;
					ans -= (double)(L[y] * P[y]) / (L[y] + now[y]) / (L[y] + now[y] + 1);
					T2.update((double)(L[y] * P[y]) / (L[y] + now[y]) / (L[y] + now[y] - 1), y);
				}
				else{
					Pd x1 = T1.T[1];
					Pd x2 = Pd((double)(L[y] * P[y]) / (L[y] + now[y]) / (L[y] + now[y] - 1), y);
					//printf("%f %d, %f %d\n", x1.Fi, x1.Se, x2.Fi, x2.Se);
					Fix2(x1, x2);
				}
			}
			
			else{
				if(now[y] < L[y])T1.update((double)(P[y] * L[y]) / (L[y] + now[y]) / (L[y] + now[y] + 1), y);
				else T1.update(0, y);
				if(now[y] > 0)T2.update((double)(P[y] * L[y]) / (L[y] + now[y]) / (L[y] + now[y] - 1), y);
				
				Fix();
			}
		}
		printf("%.20f\n", ans);
	}
	return 0;
}