#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
using namespace std;
const int N = 800005;
struct P
{
	int l, r, add, len;
	ll sum;
}t[4*N];
int v[N],k,b[N],ld[N],rd[N],fv[N],w[N];
bool cmp(int x,int y)
{
	return v[x] < v[y];
}
void build(int l,int r,int c)
{
	t[c].l = l;
	t[c].r = r;
	t[c].len = fv[r] - fv[l];
	int mid = l + r >> 1;
	if(l == r - 1) return;
	build(l, mid, c << 1);
	build(mid, r, c << 1 | 1);
}
void push_down(int c)
{
	if(t[c].add)
	{
		t[c << 1].add += t[c].add;
		t[c << 1 | 1].add += t[c].add;
		t[c << 1].sum += (ll)t[c].add * t[c << 1].len;
		t[c << 1 | 1].sum += (ll)t[c].add * t[c << 1 | 1].len;
		t[c].add = 0;
	}
}
void Add(int l,int r,int c)
{
	if(l <= t[c].l && r >= t[c].r)
	{
		t[c].add ++;
		t[c].sum += t[c].len;
		return ;
	}
	push_down(c);
	int mid = t[c].l + t[c].r >> 1;
	if(l < mid) Add(l, r, c << 1);
	if(r > mid) Add(l, r, c << 1 | 1);
	t[c].sum = t[c << 1].sum + t[c << 1 | 1].sum;
}
ll getsum(int l,int r,int c)
{
	if(l <= t[c].l && r >= t[c].r) return t[c].sum;
	ll ret = 0;
	int mid = t[c].l + t[c].r >> 1;
	push_down(c);
	if(l < mid) ret += getsum(l, r, c << 1);
	if(r > mid) ret += getsum(l, r, c << 1 | 1);
	return ret;
}
struct PP
{
	int l,r,x;
}dt[N];
bool cmpx(PP x, PP y)
{
	return x.x < y.x;
}
#define mp(x,y) make_pair(x,y)
typedef pair<int,int> per;
typedef pair<per,int> pp;
set<pp>lzs;
int main()
{
	int n,m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i ++)
		scanf("%d%d%d", &dt[i].l, &dt[i].r, &dt[i].x);
	sort(dt, dt + m, cmpx);
	for(int i = m - 1; i >= 0; i --)
	{
		pp s = mp(mp(dt[i].l, dt[i].r), dt[i].x);
		pp ss = s;
		ss.X.Y = 0;
		set<pp>::iterator it = lzs.lower_bound(ss);
		if(it != lzs.begin())
		{
			it --;
			if((*it).X.Y > dt[i].l)
			{
				pp tp = (*it), tpp = (*it);
				lzs.erase(*it);
				tp.X.Y = dt[i].l;
				lzs.insert(tp);
				if(tpp.X.Y > dt[i].r)
				{
					tpp.X.X = dt[i].r;
					lzs.insert(tpp);
				}
			}
			it = lzs.lower_bound(ss);
		}
		while(it != lzs.end() && (*it).X.X < dt[i].r)
		{
			if((*it).X.Y <= dt[i].r)
			{
				lzs.erase(*it);
				it = lzs.lower_bound(ss);
			}
			else
			{
				pp tp = (*it);
				lzs.erase(*it);
				tp.X.X = dt[i].r;
				lzs.insert(tp);
				break;
			}
		}
		lzs.insert(s);
	}
	m = 0;
	set<pp>::iterator it = lzs.begin();
	while(it != lzs.end())
	{
		v[k ++] = (*it).X.X - (*it).Y;
		v[k ++] = (*it).X.Y - (*it).Y;
		m ++;
		it ++;
	}
	for(int i = 0; i < n; i ++)
	{
		int x;
		scanf("%d",&x);
		v[k ++] = -x;
	}
	for(int i = 0; i < k; i ++) b[i] = i;
	sort(b, b + k, cmp);
	//cout << "Too simple";
	int vk = 0;
	for(int i = 0; i < k; i ++)
	{
		if(!i || v[b[i]] != v[b[i - 1]]) vk ++, fv[vk] = v[b[i]];
		if(b[i] >= 2 * m) w[b[i] - 2 * m] = vk;
		else if(b[i] % 2 == 0)ld[b[i] / 2] = vk;
		else rd[b[i] / 2] = vk;
	}
	//cout << "Too simple";
	build(1, vk, 1);
	for(int i = 0; i < m; i ++)
		Add(ld[i], rd[i], 1);
    //cout << "Too simple";
	for(int i = 0; i < n; i ++)
	{
		ll ret = 0;
		if(w[i] < vk) ret = getsum(w[i],vk,1);
		printf("%I64d\n",ret);
	}
	return 0;
}