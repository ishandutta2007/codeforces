#include <cstdio>
#include <iostream>
#include <set>
#include <algorithm>
#include <queue>
#define MN 101000

const int T = 1288;
const int moT = 400;

int cnt[MN], s[MN], a[MN];
int b[MN];
long long Ans[MN];
struct xxx{
	int l, r, id;
}q[MN];

std::set<int> st;
std::priority_queue<int, std::vector<int>, std::greater<int> > pq;

void add(int x) {if(cnt[x] == T - 1) st.insert(x); s[cnt[x]]--; cnt[x]++; s[cnt[x]]++;}
void del(int x) {if(cnt[x] == T) st.erase(x); s[cnt[x]]--; cnt[x]--; s[cnt[x]]++;}

bool cmp(xxx a, xxx b)
{
	return a.l / moT == b.l / moT ? a.r < b.r : a.l / moT < b.l / moT;
}

int main()
{
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	int m; scanf("%d", &m);
	for(int i = 1; i <= m; i++) scanf("%d%d", &q[i].l, &q[i].r), q[i].id = i;
	std::sort(q + 1, q + m + 1, cmp);
	int l = 1, r = 0;
	for(int i = 1; i <= m; i++)
	{
		while(r < q[i].r) r++, add(a[r]);
		while(l > q[i].l) l--, add(a[l]);
		while(l < q[i].l) del(a[l]), l++;
		while(r > q[i].r) del(a[r]), r--;
		
//		printf("%d %d:", l, r); for(int j = 1; j <= 5; j++) printf("%d ", s[j]); puts("");
		int lst = -1; 
		long long ans = 0;
		for(int j = 1; j < T; j++)
		{
			b[j] += s[j];
			if(!b[j]) continue;
			if(lst != -1)
			{
				int w = j + lst;
				if(w >= T) pq.push(w);
				else b[w]++;
				b[j]--;
				lst = -1;
				ans += w; 
			}
			
			int o = b[j] / 2;
			int w = j * 2;
			if(w >= T) for(int k = 1; k <= o; k++) pq.push(w);
			else b[w] += o;
			ans += 1ll * o * w;
			
			if(b[j] & 1) lst = j;
			
			b[j] = 0;
		}
		if(lst != -1) pq.push(lst);
		
		std::set<int>::iterator it = st.begin();
		for(; it != st.end(); ++it) pq.push(cnt[*it]);
		while(pq.size() > 1)
		{
			int u = pq.top(); pq.pop(); int v = pq.top(); pq.pop();
			ans += u + v; pq.push(u + v);
		}
		while(!pq.empty()) pq.pop();
		Ans[q[i].id] = ans;
	}
	for(int i = 1; i <= m; i++) printf("%lld\n", Ans[i]);
}