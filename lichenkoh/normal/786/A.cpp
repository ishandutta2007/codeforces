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
int fastscan()
{
    register int n=0;
    char ch=getchar();
    for(;(ch<48||ch>57);ch=getchar())
        ;
    for(;(ch>47&&ch<58);ch=getchar())
        n=(n<<3)+(n<<1)+ch-48;
    return n;
}
const ll mn=7002;
int k[2];
int s[2][mn];
ll vans[2][mn];
ll cnt[2][mn];
queue<pll> qv;
ll n;
const ll LOSE=0,LOOP=-1,WIN=1;
int main()
{
	memset(vans,-1,sizeof vans);
	n=fastscan();
	for (int p=0;p<2;p++) {
		k[p]=fastscan();
		for (int i=0;i<k[p];i++) s[p][i]=fastscan();
	}
	for (ll p=0;p<2;p++) {
		vans[p][0]=LOSE;
		qv.push(MP(p,0));
	}
	for (ll p=0;p<2;p++) {
		for (ll x=1;x<n;x++) {
			cnt[p][x]=k[p];
		}
	}
	while(!qv.empty()) {
		pll got=qv.front(); qv.pop();
		ll p=got.fst,x=got.snd;
		ll q=p^1;
		if (vans[p][x]==LOSE) {
			for (ll i=0;i<k[q];i++) {
				ll y=(x-s[q][i]+n)%n;
				if (vans[q][y]==LOOP) {
					vans[q][y]=WIN;
					//printf("p:%d x:%d q:%d y:%d win\n",p,x,q,y);
					qv.push(MP(q,y));
				}
			}
		}
		else if (vans[p][x]==WIN) {
			for (ll i=0;i<k[q];i++) {
				ll y=(x-s[q][i]+n)%n;
				if (vans[q][y]==LOOP) {
					cnt[q][y]--;
					if (cnt[q][y]==0) {
						//printf("p:%d x:%d q:%d y:%d lose\n",p,x,q,y);
						vans[q][y]=LOSE;
						qv.push(MP(q,y));
					}
				}
			}
		}
		else assert(0);
	}
	for (ll p=0;p<2;p++) {
		for (ll x=1;x<n;x++) {
			if (vans[p][x]==LOSE) printf("Lose ");
			else if (vans[p][x]==WIN) printf("Win ");
			else if (vans[p][x]==LOOP) printf("Loop ");
		}
		printf("\n");
	}
}