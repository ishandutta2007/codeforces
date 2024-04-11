#include<bits/stdc++.h>
using namespace std;
int n;
const int blk = 330;
int a[100010], times[100010];
class query{
	public:
		int l, r, id;
		bool operator<(const query &t)const
		{	
			if(l / blk != t.l / blk)
			{
				return l / blk < t.l / blk;
			}
			return r < t.r;
		}
}q[100010];
int c2[blk + 10], ccnt = 0;
int c1[blk + 10], tc[blk + 10];
int pos[100010];
int solve(){
	memcpy(tc, c1, sizeof(c1));
	priority_queue <int, vector <int>, greater <int> > q;
	for(int i = 1; i <= ccnt; i++)
	{
		q.push(times[c2[i]]);
	}
	int pre = 0;
	int ans = 0;
	for(int i = 1; i <= blk; i++)
	{
		if(tc[i])
		{
			if(pre && tc[pre])
			{
				if(pre + i <= blk)
				{
					tc[pre + i]++;
				}
				else
				{
					q.push(pre + i);
				}
				ans += pre + i;
				tc[i]--;
				tc[pre] = 0;
			}
			int cc = tc[i] / 2;
			if(i * 2 <= blk)
			{
				tc[i * 2] += cc;
			}
			else
			{
				for(int j =1; j <= cc; j++)
				{
					q.push(i * 2);
				}
			}
			ans += cc * i * 2;
			tc[i] -= cc * 2;
			pre = i;
		}
	}
	if(pre && tc[pre]){
		q.push(pre);
	}
	while(q.size() > 1)
	{
		int tp1 = q.top();
		q.pop();
		int tp2 = q.top();
		q.pop();
		ans += tp1 + tp2;
		q.push(tp1 + tp2);
	}
	return ans;
}
void del(int p)
{
	if(times[p] <= blk)
	{
		c1[times[p]]--;
	}
	else
	{
		swap(c2[pos[p]], c2[ccnt]);
		swap(pos[p], pos[c2[pos[p]]]);
		ccnt--;
	}
}
void add(int p)
{
	if(times[p] <= blk)
	{
		c1[times[p]]++;
	}
	else
	{
		c2[++ccnt] = p;
		pos[p] = ccnt;
	}
}
void add1(int p)
{
	del(a[p]);
	times[a[p]]++;
	add(a[p]);
}
void del1(int p)
{
	del(a[p]);
	times[a[p]]--;
	add(a[p]);
}
int nl, nr, Q, ans[100010];
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cin >> Q;
	for(int i = 1; i <= Q; i++)
	{
		cin >> q[i].l >> q[i].r;
		q[i].l--;
		q[i].r--;
		q[i].id = i;
	}
	sort(q + 1, q + Q + 1);
	c1[0] = 100000;
	nl = 0, nr = -1;
	for(int i = 1; i <= Q; i++)
	{
		while(nr < q[i].r)
		{
			add1(++nr);
		}
		while(nl > q[i].l)
		{
			add1(--nl);
		}
		while(nr > q[i].r)
		{
			del1(nr--);
		}
		while(nl < q[i].l)
		{
			del1(nl++);
		}
			ans[q[i].id] = solve();
	}
	for(int i = 1; i <= Q; i++)
	{
		cout << ans[i] << "\n";
	}
	return 0;
}