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

const int maxx = 3e5;
bool vis[maxx];
int m, a, b;
int vc;

queue<int> q;

void work(int i){
	if(vis[i]) return;
	if(i<a || !vis[i-a]) return;
	vis[i]=1; q.push(i); ++vc;
	while(q.size()){
		int x=q.front(); q.pop();
		if(x+a <= i && !vis[x+a]){
			vis[x+a]=1; ++vc;
			q.push(x+a);
		}
		if(x-b >= 0 && !vis[x-b]){
			vis[x-b]=1; ++vc;
			q.push(x-b);
		}
	}
}

int gcd(int a, int b){ return b?gcd(b, a%b):a; }

int main()
{
	cppio(); cin >> m >> a >> b;

	vis[0]=1; vc=1;

	ll ans = 0;

	int g=gcd(a, b);

	for(int i=0; i<=m;){
		if(i < a+b-g){
			work(i);
			ans += vc;
			++i;
			continue;
		}
		work(i);
		ll v = vc;
		ll df = (m - (a+b-g));
		ll dc = df / g;
		ans += v * dc * g;
		ans += dc * (dc-1) / 2 * g;
		ans += (v + dc) * (df % g + 1);
		break;
	}

	cout << ans << endl;
	return 0;
}