#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> PII;
typedef long long LL;
const int N = 300010;
int n, k, t[N], b[N];
priority_queue<PII> q;
priority_queue<int, vector<int>, greater<int> > minn; 
int main(){
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++){
		scanf("%d%d", t + i, b + i);
		q.push(make_pair(b[i], t[i]));
	}
	LL cnt = 0, ans = -1;
	int tot = 0;
	while(!q.empty()){
		PII u = q.top(); q.pop(); tot++;
		minn.push(u.second);
		cnt += u.second;
		ans = max(ans, cnt * u.first);
		if(tot == k) cnt -= minn.top(), minn.pop(), tot --;
	}
	printf("%lld\n", ans);
	return 0;
}