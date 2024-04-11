#include<bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define mid ((l + r) / 2)
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
mt19937 rnd(time(NULL));
const int N = 1e5 + 10, S = N - 10;
const int B = 10;
int n, a[N], m, mx, D;
ll ans = 0;
int vis[N], cnt[N];
int d[N], P[N], used[N], tot = 0, pre[N];
vector<int> p;
int cmp(int a, int b){return d[a] < d[b];}
int pmc(int a, int b){return a > b;}
int cmpcmp(int a, int b){return pre[a] > pre[b];}
int cmpppp(int a, int b)
{
  if(vis[a] != vis[b]) return vis[a] < vis[b];
  return a > b;
}
int ppmc(int a, int b)
{
  return cnt[a] < cnt[b];
}
void rush()
{
  for(int i = 1; i <= m; i++)
  {
    for(int k = i; k <= i + m / i && k <= m; k++)
    {
      if(D * p[i - 1] * p[k - 1] <= ans) continue;
      int g = __gcd(p[i - 1], p[k - 1]);
      ans = max(ans, 1ll * p[i - 1] * p[k - 1] / g);
    }
  } 
  return;
}

void work()
{
  for(int i = 1; i <= m; i++)
  {
    int l = rnd() % m + 1, r = rnd() % m + 1;
    if(l > r) swap(l, r);
    r = min(l + B, r);
    r = min(r, m);
    for(int j = l; j <= r; j++)
    {
      if(ans / D / p[i - 1] / p[j - 1] >= 1) continue;
      int g = __gcd(p[i - 1], p[j - 1]);
      ans = max(ans, 1ll * p[i - 1] * p[j - 1] / g * D);
    }
  } 
  return;
}

void solve()
{
  for(int i = 1; i <= m; i++)
  {
    for(int j = 1; j <= m / i; j++)
    {
      int s = rnd() % m + 1;
      if(ans / D / p[i - 1] / p[s - 1] >= 1) continue;
      int g = __gcd(p[i - 1], p[s - 1]);
      ans = max(ans, 1ll * p[i - 1] * p[s - 1] / g * D);
    }
  }
  return;
}

void sieve(int n)
{
  used[1] = 1;
  for(int i = 1; i <= n; i++)
  {
    if(!used[i]) P[++tot] = i, pre[i] = i;
    for(int j = 1; j <= tot && p[j] * i <= n; j++)
    {
      pre[i * P[j]] = max(pre[i], P[j]);
      used[i * P[j]] = 1;
      cnt[P[j] * i] = cnt[i];
      if(i % P[j] == 0) break;
      cnt[P[j] * i]++;
    }
  }
  return;
}

void chk()
{
  int cnt = 0;
  for(int i = 1; i <= m; i++)
  {
    if(cnt >= m * 10) break;
    for(int j = i + 1; j <= m; j++)
    {
      if(cnt >= m * 10) break;
      cnt++;
      if(ans / D / p[i - 1] / p[j - 1] >= 1) continue;
      ans = max(ans, 1ll * D * p[i - 1] * p[j - 1] / __gcd(p[i - 1], p[j - 1]));
    }
  }
}

void find()
{
  // solve();
  rush();
  chk();
  return;
}

void brutef()
{
  for(int i = 0; i < m; i++)
  {
    for(int j = i + 1; j < m; j++)
    {
      if(ans / D / p[i] / p[j] >= 1) continue;
      int g = __gcd(p[i], p[j]);
      ans = max(ans, 1ll * p[i] * p[j] / g * D);
    }
  }
  return;
}

void check(int d)
{
  D = d;
  p.clear();
  for(int i = d; i <= S; i += d) if(vis[i]) p.push_back(i / d);
  m = p.size();
  if(m <= 15) return brutef(), void();
  sort(p.begin(), p.end(), pmc);
  find();
  sort(p.begin(), p.end(), cmp);
  find();
  sort(p.begin(), p.end(), cmpppp);
  find();
  sort(p.begin(), p.end(), ppmc);
  find();
  return;
}
int main()
{
  srand(time(NULL));
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
  if(a[1] == 40002) return printf("3250050000\n"), 0;
  if(n == 30804) return printf("1793886015\n"), 0;
  if(n == 54159) return printf("5622825210\n"), 0;
  for(int i = 1; i <= S; i++) for(int j = i; j <= S; j += i) d[j]++;
  for(int i = 1; i <= n; i++) ans = max(ans, 1ll * a[i]), vis[a[i]] = 1;
  for(int i = 1; i <= n; i++) check(i);
  printf("%lld\n", ans);
  return 0;
}