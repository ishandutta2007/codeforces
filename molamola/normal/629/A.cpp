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

char ch[110][110];
int p[110], q[110];

int main(){
	int n; scanf("%d", &n);
	rep(i, n)scanf("%s", ch[i]);
	rep(i, n)rep(j, n)if(ch[i][j] == 'C')p[i]++, q[j]++;
	int ans = 0;
	rep(i, n)ans += p[i] * (p[i]-1) / 2;
	rep(i, n)ans += q[i] * (q[i]-1) / 2;
	printf("%d", ans);
	return 0;
}