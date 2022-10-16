#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string.h>

using namespace std;

typedef long long LL;


const int maxN = 1000005,
          maxM = 100005,
          Base = (1<<20),
          Siz = (1<<21);

int seg[Siz];
void insert(int a, int v){
	a += Base;
	while(a){
		seg[a] += v;
		a /= 2;
	}
}
int query(int L, int R){
	L += Base; R += Base;
	int res = seg[L];
	if(R != L) res += seg[R];
	
	while(L/2 != R/2){
		if(L % 2 == 0) res += seg[L+1];
		if(R % 2 == 1) res += seg[R-1];
		L /= 2; R /= 2;
	}
	return res;
}


char str[maxN];
int n, m;
stack<int> S;
int rightpar[maxN];

struct Event {
	int begin, end, pos;
	Event(int _b=0, int _e=0, int _p=0) : begin(_b), end(_e), pos(_p) {}
	
	bool operator<(const Event &E) const {
		return begin < E.begin;
	}
};

Event E[maxM];
int res[maxN];


int main(){
	scanf("%s%d", str, &m);
	n = strlen(str);
	
	for(int i = 0; i < n; i++){
		if(str[i] == '('){
			S.push(i);
		} else {
			if(!S.empty()){
				int v = S.top(); S.pop();
				rightpar[v] = i;
			}
		}
	}
	
	for(int i = 0; i < m; i++){
		int l, r;
		scanf("%d%d", &l, &r);
		l--; r--;
		E[i] = Event(l,r,i);
	}
	
	sort(E, E+m);
	
	int last = n;
	for(int i = m-1; i >= 0; i--){
		while(last > E[i].begin){
			last--;
			
			if(rightpar[last]){
				//printf("%d: %d\n", last, rightpar[last]);
				insert(rightpar[last], 2);
			}
		}
		//printf("[%d,%d]\n", E[i].begin, E[i].end);
		res[E[i].pos] = query(0, E[i].end);
	}
	
	for(int i = 0; i < m; i++) printf("%d\n", res[i]);
}