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

int n, lst;
int tbl[100005];

int main(){
	scanf("%d", &n); lst = 999999;
	for(int i = 0; i < n; i++) scanf("%d", &tbl[i]);
	int p = n-1;
	while(p >= 0){
		if(tbl[p] > lst) break; else lst = tbl[p];
		p--;
	}
	printf("%d\n", p+1);
}