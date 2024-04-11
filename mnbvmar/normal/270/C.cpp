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

typedef long long LL;

//map<int,LL> M;
//map<int,LL>::iterator it;
int n,k[100005],a[100005];

int main(){
	scanf("%d", &n);
	int mval = 0;
	long long tmp = 1;
	for(int i = 0; i < n; i++){
		scanf("%d%d", &k[i], &a[i]);
		
		int b = 0; tmp = 1;
		while(a[i] > tmp){ tmp *= 4; b++; }
		//printf("%d\n", b);
		mval = max(mval, k[i]+max(b,1));
	}
	printf("%d\n", mval);
}