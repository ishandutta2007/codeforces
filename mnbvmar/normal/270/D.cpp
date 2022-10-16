#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <vector>
#include <complex>
#include <string.h>
#include <sstream>
#include <queue>
#include <stack>
#include <list>
#include <deque>
#include <set>
#include <map>

using namespace std;

int n, m;
int tab[5005];
int d[5005][5005];

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%d%*f", &tab[i]);
	}
	
	int bst;
	
	for(int j = 1; j <= m; j++) d[0][j] = 0;
	d[0][tab[0]] = 1;
	bst = 1;
	
	for(int i = 1; i < n; i++){
		int mv = 0;
		for(int j = 0; j <= tab[i]; j++){
			mv = max(mv, d[i-1][j]);
			d[i][j] = d[i-1][j];
		}
		d[i][tab[i]] = max(mv, 0)+1;
		bst = max(bst, d[i][tab[i]]);
		for(int j = tab[i]+1; j <= m; j++) d[i][j] = d[i-1][j];
	}
	printf("%d\n", n-bst);
}