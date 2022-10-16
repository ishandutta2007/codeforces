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

int t, a;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &a);
		bool ok = false;
		for(int n = 3; n <= 500; n++){
			if(a*n == 180*(n-2)) ok = true;
		}
		printf(ok ? "YES\n" : "NO\n");
	}
	return 0;
}