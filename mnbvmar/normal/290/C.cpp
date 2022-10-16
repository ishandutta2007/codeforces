#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>

using namespace std;

int it, tux, foo, bar, baz, quz;

int main(){
	scanf("%d", &tux);
	foo=0; bar=0; baz=0; quz=1;
	for(; tux != 0; tux--){
		int pur;
		scanf("%d", &pur);
		foo += pur;
		bar++;
		it = (max(foo*quz, bar*baz) == foo*quz);
	
		if(it){
			baz=foo;
			quz=bar;
		}
	}
	printf("%.8lf\n", (double)baz/quz);
}