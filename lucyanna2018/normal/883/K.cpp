#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

#define ran 202222

int n;
int lo[ran], hi[ran];
pair<int, int> v[ran];
priority_queue<pair<int, int> > q;
int ans[ran];

bool upd(int id, int lim) {
//	printf("-- %d %d\n", id, lim);
	if (hi[id] > lim) {
		hi[id] = lim;
		q.push(make_pair(-hi[id], id));
	}
	return (hi[id] >= lo[id]);
}

int main() {
	scanf("%d", &n);
	for(int i=0;i<n;i++) {
		int x, y; scanf("%d%d", &x, &y);
		lo[i] = x; hi[i] = x+y;
		v[i] = make_pair(y+x, i);
	}
	sort(v, v+n);
	while(!q.empty()) q.pop();
	for(int i=0;i<n;i++) q.push(make_pair(-v[i].first, v[i].second));
	
	memset(ans, -1, sizeof ans);
	while(!q.empty()) {
		pair<int, int> p = q.top(); q.pop();
		int id = p.second, val = p.first;
//		printf("%d %d\n", id, val);
		if (ans[id]!=-1) continue;
		ans[id] = hi[id];
		
		int lim = hi[id]+1;
		bool f = true;
		if (id>0) f &= upd(id-1, lim);
		if (id<n-1) f &= upd(id+1, lim);
		if (!f) {
			puts("-1"); return 0;
		}
	}
	
	long long tot = 0LL;
	for(int i=0;i<n;i++)
		tot += hi[i] - lo[i];
	printf("%I64d\n", tot);
	for(int i=0;i<n;i++) printf("%d%c", hi[i], i<n-1 ? ' ' : '\n');
	
	return 0;
}