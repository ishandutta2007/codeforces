#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef pair<int,int> PII;

const int N=101000;
short cnt[610][N];
int ff[610][N];
int fl[610],fr[610],pl[610],pr[610],off[610],a[N],x,l,r;
int n,m,T,B,ty;
PII rg[610];
int find(int x,int c) {
	if (ff[x][c]==0||ff[x][c]==c) return ff[x][c]=c;
	else return ff[x][c]=find(x,ff[x][c]);
}
void rebuild(int c,int l,int r) {
	rep(j,fl[c],fr[c]+1) a[j]=find(c,a[j]);
	rep(j,l,r+1) if (a[j]-off[c]>x) {
		cnt[c][a[j]]--;
		a[j]-=x;
		cnt[c][a[j]]++;
	}
}

int query(int c1,int l,int r) {
	rep(j,fl[c1],fr[c1]+1) a[j]=find(c1,a[j]);
	int cnt=0;
	rep(j,l,r+1) if (find(c1,a[j])==x+off[c1]) cnt++;
	return cnt;
}
int query(int c) {
	if (x+off[c]>=rg[c].fi&&x+off[c]<=rg[c].se) return cnt[c][x+off[c]];
	else return 0;
}

void gao(int i) {
	if (rg[i].fi+x>rg[i].se) return;
	if (rg[i].fi+x+x<=rg[i].se) {
		off[i]+=x;
		rep(j,rg[i].fi+1,rg[i].fi+x+1) {
			ff[i][j]=j+x;
			cnt[i][j+x]+=cnt[i][j];
			cnt[i][j]=0;
		}
		rg[i].fi+=x;
	} else {
		per(j,rg[i].fi+x+1,rg[i].se+1) {
			ff[i][j]=j-x;
			cnt[i][j-x]+=cnt[i][j];
			cnt[i][j]=0;
		}
		rg[i].se=rg[i].fi+x;
	}
}
int main() {
	scanf("%d%d",&n,&m);
	B=max(sqrt(n)*0.5+1,180.0);
	rep(i,0,n) scanf("%d",a+i);
	rep(i,0,n) cnt[i/B][a[i]]++;
	T=(n-1)/B+1;
	rep(i,0,T) rg[i]=mp(0,100001),off[i]=0;
	rep(i,0,T) fl[i]=i*B, fr[i]=min(i*B+B-1,n-1);
	rep(i,0,m) {
		scanf("%d%d%d%d",&ty,&l,&r,&x);
		--l; --r;
		if (l/B==r/B) {
			if (ty==1) rebuild(l/B,l,r);
			else printf("%d\n",query(l/B,l,r));
		} else {
			int c1=l/B,c2=r/B;
			int ret=0;
			if (ty==1) {
				rebuild(c1,l,fr[c1]);
				rebuild(c2,fl[c2],r);
				rep(j,c1+1,c2) gao(j);
			} else {
				ret+=query(c1,l,fr[c1]);
				ret+=query(c2,fl[c2],r);
				rep(j,c1+1,c2) ret+=query(j);
				printf("%d\n",ret);
			}
		}
	}
}