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

int chk[600060];

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	int low = 1, high = 6000000;
	int ans = high;
	while(low <= high){
		int mid = (low + high) / 2;
		int a = mid / 2;
		int b = mid / 3;
		int c = mid / 6;
		int ok = 1;
		if(a + b - c < n + m)ok = 0;
		if(a < n)ok = 0;
		if(b < m)ok = 0;
		if(ok)ans = mid, high = mid - 1;
		else low = mid + 1;
	}
	printf("%d", ans);
	return 0;
}