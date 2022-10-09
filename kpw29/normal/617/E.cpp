#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 1501000
int Left[maxn], Right[maxn], root[maxn];
int t[maxn], a, b, n, zap, ROOT;
ll wyn[maxn];
PII skal[maxn];
int queries[maxn];
inline int readint() 
{
    int x = 0; char c;
    for(; ((c<48 || c>57) && c != '-'); c = getchar());
    for(; c>47 && c<58 ; c = getchar()) x = (x<<1) + (x<<3) + c - '0';
	return x;
}
bool cmp(int a, int b) {
	if (root[a] != root[b]) return (root[a] < root[b]);
	if (Right[a] != Right[b]) return (Right[a] < Right[b]);
	if (Left[a] != Left[b]) return (Left[a] < Left[b]);
	return a < b;
}

ll WYN = 0;
int cnt[maxn], pref[maxn], k;
inline void add(int i) {
	int a = pref[i];
	WYN += cnt[k ^ a];
	cnt[a]++;
}

inline void remove(int i) {
	int a = pref[i];
	cnt[a]--;
	WYN -= cnt[k ^ a];
}

int main()
{
	n = readint(); zap = readint(); k =readint();
	pref[0] = 0;
	for (int i=1; i<=n; ++i) {
		a = readint();
		t[i] = a;
		pref[i] = pref[i-1] ^ a;
	}
	int AKT = 0;
	ROOT = sqrt(zap);
	//cnt[0] = 1;
	for (int z=1; z<=zap; ++z) {
		scanf("%d%d", &a, &b);
		queries[++AKT] = z;
		root[z] = (a / ROOT);
		Left[z] = a; Right[z] = b;
	}
	int currR = 1, currL = 1;
	sort(queries + 1, queries + AKT + 1, cmp);
	for (int i=1; i<=AKT; ++i) {
		int L = Left[queries[i]], R = Right[queries[i]] + 1;
		L--;
		while (currL > L) add(--currL);
		while (currR < R) add(currR++);
		while (currL < L) remove(currL++);
		while (currR > R) remove(--currR);
		wyn[queries[i]] = WYN;
	}
	//koniec kolejnego obrotu petli
	for (int i=1; i<=zap; ++i) cout << wyn[i] << endl;
}