#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=1e9;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
ll n,m;
char a[54][54];
char b[54][54];
bool match(ll x,ll y, string s) {
	if (x<0||x+1>=n||y<0||y+1>=m) return false;
	return a[x][y]==s[0]&&a[x][y+1]==s[1]&&a[x+1][y]==s[2]&&a[x+1][y+1]==s[3];
}
bool matchvert(ll x,ll y, string s) {
	if (x<0||x+1>=n||y<0||y>=m) return false;
	return a[x][y]==s[0]&&a[x+1][y]==s[1];
}
vector<pll> gans;
void modify(ll x, ll y, string s) {
	/*for (ll x=0;x<n;x++) {
		//printf("%s\n",a[x]);
	}
	//printf("\n");
	//printf("Modify:%d,%d\n",x,y);*/
	if (s=="UUDD") assert(match(x,y,"LRLR"));
	else if (s=="LRLR") assert(match(x,y,"UUDD"));
	else assert(0);
	gans.PB(MP(x,y));
	a[x][y]=s[0];
	a[x][y+1]=s[1];
	a[x+1][y]=s[2];
	a[x+1][y+1]=s[3];
}
bool nice(ll x, ll y) {
	return (x%2==0&&y%2==0);
}
void solve() {
	gans.clear();
	for (ll x=0;x<n-1;x++) {
		for (ll y=0;y<m-1;y++) {
			if (match(x,y,"UUDD")) {
				modify(x,y,"LRLR");
			}
		}
	}
	while(1) {
		bool change=false;
		for (ll x=0;x<n-1;x++) {
			ll prev=-1;
			ll isl;
			for (ll y=0;y<m;y++) {
				if (matchvert(x,y,"UD")) {
					if (prev!=-1) {
						//printf("x:%d prev:%d to y:%d\n",x,prev,y);
						for (ll t=prev+1;t<y;t+=2) {
							modify(x,t,"UUDD");
						}
						for (ll t=prev;t<y;t+=2) {
							modify(x,t,"LRLR");
						}
						change=true;
					}
					else {
						//printf("setting prev at y:%d\n",y);
						prev=y;
						isl=0;
					}
				}
				else {
					string need=isl?"LL":"RR";
					if (!matchvert(x,y,need)) {
						//printf("Did not get %s at %d %d.\n",need.c_str(),x,y);
						prev=-1;
					}
					if (y==m-1&&prev!=-1) {
						//printf("x:%d prev:%d to y:%d\n",x,prev,y);
						for (ll t=prev+1;t<y;t+=2) {
							modify(x,t,"UUDD");
						}
						for (ll t=prev;t<y;t+=2) {
							modify(x,t,"LRLR");
						}
						change=true;
					}
				}
				isl^=1;
			}
		}
		if (!change) break;
	}
	//for (ll x=0;x<n;x++) {
	//	//printf("%s\n",a[x]);
	//}
	////printf("Done\n");
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	scanf("%d%d\n",&n,&m);
	for (ll x=0;x<n;x++) scanf("%s\n",a[x]);
	for (ll x=0;x<n;x++) scanf("%s\n",b[x]);
	solve();
	vector<pll> final=gans;
	memcpy(a,b,sizeof a);
	solve();
	reverse(gans.begin(),gans.end());
	for (auto &w:gans) final.PB(w);
	printf("%d\n",(ll)final.size());
	for (auto &w:final) printf("%d %d\n",w.first+1,w.second+1);
}