#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define il inline
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for (int i = x; i <= y; i++)
#define rrep(i, x, y) for (int i = x; i >= y; i--)
#define rep0(i, n) for (int i = 0; i < (n); i++)
#define per0(i, n) for (int i = (n)-1; i >= 0; i--)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (x).size()
#define All(x) (x).begin(), (x).end()
#define vi vector<int>
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
inline ll read1()
{
	ll x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int Maxn=200005;
int n,a[Maxn];
vector<int> V[Maxn];
bool isp[Maxn];
void _init(){
	memset(isp,1,sizeof(isp));
	isp[0]=isp[1]=0;
	for (int i=2;i<Maxn;i++){
		if (isp[i]){
			for (int j=i+i;j<Maxn;j+=i){
				isp[j]=0;
			}
		}
	}
}
int main(){
	_init();
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	ll ans=1;
	for (int i=1;i<=n;i++){
		int x=a[i];
		for (int j=2;j*j<=x;j++){
			if (isp[j]){
				if (x%j==0){
					int cc=0;
					while (x%j==0){
						x/=j;cc++;
					}
					V[j].pb(cc);
				}
			}
		}
		if (x){
			V[x].pb(1);
		}
	}
	for (int i=1;i<=200000;i++){
		if (isp[i]){
		//cout<<i<<' '<<V[i].size()<<endl;
			if (V[i].size()<=n-2){
				continue;
			}
			
			sort(V[i].begin(),V[i].end());
			if (V[i].size()==n-1){
				for (int j=0;j<V[i][0];j++) ans=ans*i;
			}
			else{
				for (int j=0;j<V[i][1];j++) ans=ans*i;
			}
		}
	}
	printf("%lld\n",ans);
}