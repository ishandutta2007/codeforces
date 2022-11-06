#include <bits/stdc++.h>
#define lowbit(i) (i & (-i))
using namespace std;

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
struct Node
{
	int l,r;
	bool operator <(const Node &b)const
	{
		return r - l != b.r - b.l ? r - l > b.r - b.l : r > b.r;
	}
};
int n,q;
map<int,int> bit, pos;

int sum(int i)
{
	int res = 0;
	for(; i; i -= lowbit(i))
		if(bit.count(i))
			res += bit[i];
	return res;
}

void add(int i, int x)
{
    while(i <= n)
    {
        bit[i] += x;
        i += lowbit(i);
    }
}

set<Node> seg;
set<int> a;

int main()
{
	n = read();
	q = read();
	a.insert(0);
	a.insert(n + 1);
	seg.insert((Node){ 1, n });
	for(int i = 1; i <= q; i ++)
	{
		int id;
		id = read();
		if(id == 0)
		{
			int l,r;
			l = read();
			r = read();
			printf("%d\n", sum(r) - sum(l - 1));
		}
		else
		{
			if(pos[id] == 0)
			{
				Node now = *seg.begin();
				seg.erase(now);
				int mid = (now.l + now.r + 1) >> 1;
				pos[id] = mid;
				a.insert(mid);
				add(mid, 1);
				if(now.l <= mid - 1) seg.insert((Node){ now.l, mid - 1 });
				if(mid + 1 <= now.r) seg.insert((Node){ mid + 1, now.r });
			}
			else
			{
				int bef, mid, nxt;
				set<int>::iterator x, y;
				mid = pos[id];
				x = y = a.find(mid);
				bef = *-- x;
				nxt = *++ y;
				//cout << bef << " " << nxt << endl;
				if(bef + 1 <= mid - 1) seg.erase((Node){ bef + 1, mid - 1 });
				if(mid + 1 <= nxt - 1) seg.erase((Node){ mid + 1, nxt - 1 });
				if(bef + 1 <= nxt - 1) seg.insert((Node){ bef + 1, nxt - 1 });
				a.erase(mid);
				add(mid, -1);
				pos[id] = 0;
			}
		}
	}
	return 0;
}