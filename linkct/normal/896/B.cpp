#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;

int n, m, c, bound, a[MAXN];

int main(){
	int l, r, v, p;
	cin >> n >> m >> c;
	bound = (c + 1) >> 1;
	l = 0, r = n + 1;
	a[l] = 0, a[r] = c + 1;
	while(cin >> v){
		if(v <= bound){
			if(v >= a[l]) p = ++ l;
			else for(p = l; a[p - 1] > v; -- p) ;
		}else{
			if(v <= a[r]) p = -- r;
			else for(p = r; a[p + 1] < v; ++ p) ;
		} cout << p << endl << flush;
		a[p] = v;
		if(l + 1 == r) break;
	} return 0;
}