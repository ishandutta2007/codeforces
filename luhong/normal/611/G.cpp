#include <cstdio>
#define mod 1000000007
#define MN 501000

typedef long long ll;

struct xxx{
	ll x, y;
	xxx(){}
	xxx(ll a, ll b) {x = a; y = b;}
}p[MN];

ll s[MN];
xxx ss[MN];
int n, now = 3;

int add(int a, int b) {return a + b >= mod ? a + b - mod : a + b;}
int sub(int a, int b) {return a - b < 0 ? a - b + mod : a - b;}

ll operator / (xxx a, xxx b) {return a.x * b.y - a.y * b.x;}
xxx operator - (xxx a, xxx b) {return xxx(a.x - b.x, a.y - b.y);}
xxx operator + (xxx a, xxx b) {return xxx(a.x + b.x, a.y + b.y);}
xxx operator * (xxx a, int b) {return xxx(a.x * b, a.y * b);}

int nxt(int p) {return p == n ? 1 : p + 1;}
int lst(int p) {return p == 1 ? n : p - 1;}

xxx sum3(int i, int j)
{
	if(i <= j) return ss[j] - ss[i];
	else return ss[n] - ss[i] + ss[j];
}

ll sum2(int i, int j)
{
	if(i <= j) return ((s[j] - s[i]) % mod + mod) % mod;
	else return ((s[n] - s[i] + s[j]) % mod + mod) % mod;
}

ll sum(int i, int j)
{
	if(i <= j) return s[j] - s[i] + (p[i] / p[j]);
	else return s[n] - s[i] + s[j] + (p[i] / p[j]);
}

int len(int i, int j) 
{
	if(i <= j) return j - i;
	else return n - i + j;
}

void Add(int i, int w, int &s1, xxx &s3)
{
	w = (w + mod) % mod;
	s1 = add(s1, 1ll * w * ((p[i] / p[lst(i)]) % mod + mod) % mod);
	xxx o = p[lst(i)] - p[i];
	o.x = ((o.x % mod * w) % mod + mod) % mod;
	o.y = ((o.y % mod * w) % mod + mod) % mod;
	s3.x = add(s3.x, o.x); s3.y = add(s3.y, o.y);
}

void Del(int i, int w, int &s2, xxx &s4)
{
	w = (w + mod) % mod;
	s2 = sub(s2, 1ll * w * ((p[i] / p[lst(i)]) % mod + mod) % mod);
	xxx o = p[lst(i)] - p[i];
	o.x = ((o.x % mod * w) % mod + mod) % mod;
	o.y = ((o.y % mod * w) % mod + mod) % mod;
	s4.x = sub(s4.x, o.x); s4.y = sub(s4.y, o.y);
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%lld%lld", &p[i].x, &p[i].y);
	for(int i = 1; i <= n; i++) s[i] = s[i - 1] + (p[i] / p[lst(i)]);
	for(int i = 1; i <= n; i++) ss[i] = ss[i - 1] + (p[lst(i)] - p[i]);
	int s1 = 0, s2 = 0;
	xxx s3 = xxx(0, 0), s4 = xxx(0, 0);
	for(int i = 3; i < n; i++)
		Add(i, n - 3 - 2 * len(now, i), s2, s4);
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		Add(lst(i), n - 3 - 2 * len(now, lst(i)), s2, s4);
		
		while(sum(i, now) < sum(now, i))
		{
			Del(now, n - 3, s2, s4);
			Add(now, n - 3, s1, s3);
			s1 = sub(s1, 2 * sum2(nxt(i), now) % mod);
			s3 = s3 - (sum3(nxt(i), now) * 2);
			s2 = add(s2, 2 * sum2(now, lst(i)) % mod);
			s4 = s4 + (sum3(now, lst(i)) * 2);
			s3.x = (s3.x % mod + mod) % mod;
			s3.y = (s3.y % mod + mod) % mod;
			s4.x = (s4.x % mod + mod) % mod;
			s4.y = (s4.y % mod + mod) % mod;
			now = nxt(now);
		}
		
		ans = add(ans, s1); ans = add(ans, ((xxx(-p[i].x, -p[i].y) / s3) % mod + mod) % mod);
		ans = add(ans, s2); ans = add(ans, ((xxx(-p[i].x, -p[i].y) / s4) % mod + mod) % mod);
		
		if(nxt(nxt(i)) == now) Del(nxt(nxt(i)), n - 3 - 2 * len(nxt(nxt(i)), now), s2, s4);
		else Del(nxt(nxt(i)), n - 3 - 2 * len(nxt(nxt(i)), now), s1, s3);
	}
	printf("%lld\n", 1ll * ans * (mod + 1 >> 1) % mod);
}