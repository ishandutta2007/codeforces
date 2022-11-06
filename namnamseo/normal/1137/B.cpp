#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
void read(int& x){ scanf("%d",&x); }
void read(ll& x){ scanf("%lld",&x); }
void read(pp& x){ scanf("%d%d",&x.first, &x.second); }
void read(pll& x){ scanf("%lld%lld",&x.first, &x.second); }
template<typename T,typename... Args>
void read(T& a,Args&... b){ read(a); read(b...); }
void cppio(){ ios_base::sync_with_stdio(0); cin.tie(0); }
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define x first
#define y second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define sz(x) (int)(x).size()

char s[500010];
char t[500010];
int n;

int one;

int f[500010];

int C;

void put(int p, int v){
	s[p] = '0';
	if(v && C){
		s[p] = '1';
		--C;
	}
}

int main()
{
	cppio();

	cin >> s >> t;
	n = strlen(t);

	for(int i=1, m=0; i<n; ++i){
		while(m && t[i] != t[m]) m=f[m-1];
		if(t[i] == t[m]) ++m;
		f[i] = m;
	}

	int m = strlen(s);
	for(int i=0; i<m; ++i) C += (s[i] == '1');

	for(int i=0, j=0; i<m; ++i){
		put(i, t[j]-'0');
		if(++j == n){
			j = f[j-1];
		}
	}

	for(int i=m-1; 0<=i; --i) if(C && s[i] != '1'){
		s[i] = '1';
		--C;
	}
	cout << s << endl;

	return 0;
}