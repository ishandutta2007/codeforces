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

int n;
char s[5010];

int main()
{
	cppio(); cin >> s; n = strlen(s);

	string half(s, n/2);

	bool ok=0;
	rep(i, half.length()) if(half[i]!=half[0]){ ok=1; break; }

	if(!ok){
		cout << "Impossible" << endl;
		return 0;
	}

	for(int i=1; i<n; ++i){
		string x = string(s+i, n-i) + string(s, i);
		if(x == s) continue;
		int l=0, r=n-1;
		while(l<r && x[l]==x[r]) ++l, --r;
		if(l>=r){
			cout << 1 << endl;
			return 0;
		}
	}

	cout << 2 << endl;
	return 0;
}