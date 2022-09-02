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

int a[2][370];

int main(){
	int n;
	scanf("%d", &n);
	rep(i, n){
		char ch[2];
		int x, y;
		scanf("%s%d%d", ch, &x, &y);
		for(int j=x;j<=y;j++){
			a[ch[0] == 'M'][j]++;
		}
	}
	int ans = 0;
	for(int i=1;i<=366;i++)ans = max(ans, min(a[0][i], a[1][i]) * 2);
	printf("%d", ans);
	return 0;
}