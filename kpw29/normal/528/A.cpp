#include <cstdio>
#include <algorithm>
#include <queue>
#define maxn 1000010
using namespace std;
char s[maxn];
typedef long long int ll;
struct node
{
	int lewo, prawo;
	int wyn;
};

const int R = (1 << 18);
node dr1[2*maxn], dr2[2*maxn];
int ile_w[maxn], x, t[maxn];
int n, T, help;

void obsluz1(int x)
{
	dr1[x].lewo = dr1[2*x].lewo;
	if (dr1[2*x].lewo == ile_w[2*x]) dr1[x].lewo+=dr1[2*x+1].lewo;
	dr1[x].prawo = dr1[2*x+1].prawo;
	if (dr1[2*x+1].prawo == ile_w[2*x+1]) dr1[x].prawo+=dr1[2*x].prawo;
	dr1[x].wyn = max(max(dr1[2*x].wyn, dr1[2*x+1].wyn), dr1[2*x].prawo + dr1[2*x+1].lewo);
}

void obsluz2(int x)
{
	dr2[x].lewo = dr2[2*x].lewo;
	if (dr2[2*x].lewo == ile_w[2*x]) dr2[x].lewo+=dr2[2*x+1].lewo;
	dr2[x].prawo = dr2[2*x+1].prawo;
	if (dr2[2*x+1].prawo == ile_w[2*x+1]) dr2[x].prawo+=dr2[2*x].prawo;
	dr2[x].wyn = max(max(dr2[2*x].wyn, dr2[2*x+1].wyn), dr2[2*x].prawo + dr2[2*x+1].lewo);
}

void akt1(int x)
{
	x+=R-1;
	dr1[x].wyn=(dr1[x].wyn+1)%2;
	dr1[x].lewo=(dr1[x].lewo+1)%2;
	dr1[x].prawo=(dr1[x].prawo+1)%2;
	x/=2;
	while (x > 0)
	{
		obsluz1(x);
		x/=2;
	}
}

void akt2(int x)
{
	x+=R-1;
	dr2[x].wyn=(dr2[x].wyn+1)%2;
	dr2[x].lewo=(dr2[x].lewo+1)%2;
	dr2[x].prawo=(dr2[x].prawo+1)%2;
	x/=2;
	while (x > 0)
	{
		obsluz2(x);
		x/=2;
	}
}

int main()
{
	int zap, m;
	scanf("%d%d%d", &n, &m, &zap);
	m--; n--;
	for (int i=1; i<=n; ++i) s[i] = '0';
	for (int i=1; i<=n; i++)
	{
		t[i] = s[i]-'0';
		help = i+R-1;
		ile_w[help]=1;
		if (s[i] == '0')
		{
			dr1[help].wyn=1;
			dr1[help].lewo=1;
			dr1[help].prawo=1;
		}
	}
	for (int i=1; i<=m; ++i) s[i] = '0';
	for (int i=1; i<=m; i++)
	{
		help = i+R-1;
		ile_w[help]=1;
		if (s[i] == '0')
		{
			dr2[help].wyn=1;
			dr2[help].lewo=1;
			dr2[help].prawo=1;
		}
	}
	for (int i=R-1; i>0; --i) ile_w[i] = ile_w[2*i]+ile_w[2*i+1];
	for (int i=R-1; i>0; --i) obsluz1(i), obsluz2(i);
	for (int i=1; i<=zap; ++i)
	{
		char zn;
		scanf(" %c%d", &zn, &x);
		if (zn == 'V') akt1(x);
		else akt2(x);
		ll w1 = dr1[1].wyn + 1;
		ll w2 = dr2[1].wyn + 1;
		//if (w1 > n) w1--;
		//if (w2 > m) w2--;
		printf("%I64d\n", w1*w2);
	}
}