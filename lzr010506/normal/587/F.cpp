#include<bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; ++ i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define two(x) (1 << (x))
#define lowbit(x) ((x & (-x)))
using namespace std;
inline int ReadInt()
{
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9')
	{
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
typedef long long ll;
typedef pair<int ,int> PII;

const int N = 201000;
int tot, rk[N * 4], sa[N];
pair<PII,int> pos[N];
char s[N];
int p[N];

void init()
{
	for (int i = 1; i <= tot; i ++) rk[i] = p[i];
	for (int j = 0; j < 19; j ++)
	{
		for (int i = 1; i <= tot; i ++)
			pos[i] = mp(mp(rk[i], rk[i + two(j)]),i);
		sort(pos + 1, pos + tot + 1);
		int cnt = 0;
		for (int i = 1; i <= tot; i ++)
		{
			rk[pos[i].se] = cnt;
			cnt += (pos[i].fi != pos[i + 1].fi);
		}
		if (cnt == tot) break;
	}
	for(int i = 1; i <= tot; i ++) rk[i] ++;
	for(int i = 1; i <= tot; i ++) sa[rk[i]] = i;
}
int query(int l,int r,int c,int len)
{
	r ++;
	l --;
	while (l + 1 < r)
	{
		int mid = (l + r) >> 1;
		if (p[sa[mid] + len - 1] >= c) r = mid;
		else l = mid;
	}
	return r;
}

int n,q,l[N],r[N],c[N],ocr[N],sl[N],sr[N];
int bv[N],bid[N],bcnt;
ll ret[N],ans[N];
vector<PII> ql[N],qr[N];
vector<pair<PII,int> > Qr[N];

void modify(int x,int s)
{
	for (; x <= tot; x += lowbit(x)) c[x] += s;
}
int query(int x)
{
	int s = 0;
	for (; x; x -= lowbit(x)) 
		s += c[x];
	return s;
}

const int R = 210;
int main()
{
	n = ReadInt();
	q = ReadInt();
	rep(i,1,n+1)
	{
		scanf("%s",s);
		int len = strlen(s);
		l[i] = tot + 1;
		rep(j,0,len)
			p[++ tot] = s[j] - 'a' + 1;
		p[++ tot] = 29 + i;
		r[i] = tot;
		if (len > R)
		{
			bid[i] = ++ bcnt;
			bv[bcnt] = i;
		}
	}
	init();
	rep(i, 1, n + 1)
	{
		int pl = 1, pr = tot;
		rep(j,l[i],r[i])
		{
			int ql = query(pl, pr, p[j], j - l[i] + 1);
			int qr = query(pl, pr, p[j] + 1, j - l[i] + 1) - 1;
			pl = ql;
			pr = qr;
		}
		sl[i] = pl;
		sr[i] = pr;
	}
	rep(i, 1, q + 1)
	{
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		if (bid[k])
			Qr[k].pb(mp(mp(l,r),i));
		else
		{
			qr[r].pb(mp(k,i));
			qr[l - 1].pb(mp(k,-i));
		}
	}
	rep(i, 1, bcnt + 1)
	{
		int v = bv[i];
		for (int j = 1; j <= tot; j ++) ocr[j] = 0;
		for (int j = l[v]; j < r[v]; j ++)
			ocr[rk[j]] ++;
		for (int j = 1; j <= tot; j ++) ocr[j] += ocr[j - 1];
		for (int j = 1; j <= n; j ++)
			ret[j] = ret[j - 1] + ocr[sr[j]] - ocr[sl[j] - 1];
		for (auto que:Qr[v])
		{
			int l = que.fi.fi, r = que.fi.se, id = que.se;
			ans[id] = ret[r] - ret[l - 1];
		}
	}
	rep(i, 1, n + 1)
	{
		modify(sl[i], 1);
		modify(sr[i] + 1, -1);
		for (auto p:qr[i])
		{
			int id = p.se, w = 1, v = p.fi;
			if (id < 0) w = -1, id *= -1;
			rep(j,l[v],r[v])
				ans[id] += w * query(rk[j]);
		}
	}
	rep(i, 1, q + 1)
		printf("%I64d\n",ans[i]);
	return 0;
}