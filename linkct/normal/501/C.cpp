#include <cstdio>
#include <queue>
const int MAXN = 70000;
using std :: priority_queue;

struct heapData{
	int n, d, s;
	bool operator < (const heapData& rhs) const{
		return d > rhs.d;
	}
};
priority_queue <heapData> h;
int d[MAXN], s[MAXN], n, cnt;
heapData now;

int main(){
	int i;
	scanf("%d", &n);
	for(i = 0; i < n; ++ i){
		scanf("%d%d", &d[i], &s[i]);
		h.push((heapData){i, d[i], s[i]});
		cnt += d[i];
	}
	printf("%d\n", cnt >> 1);
	while(!h.empty()){
		while(!h.empty() && d[h.top().n] != h.top().d) h.pop();
		if(h.empty()) break;
		now = h.top();
		h.pop();
		if(now.d == 0) continue;
		printf("%d %d\n", now.n, now.s);
		d[now.s] --;
		s[now.s] ^= now.n;
		h.push((heapData){now.s, d[now.s], s[now.s]});
	}
	return 0;
}