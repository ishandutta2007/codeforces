#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;

#define y1 safdasd

struct event { int x,ty,y1,y2;};
vector<event> evt;
const int N=101000;
int ret[N*4],cov[N*4],x1,y1,x2,y2;
VI vy;
int K,m,n,k,prex,ans;
bool cmp(const event &a,const event &b) {
	return a.x<b.x;
}
void cover(int p,int l,int r,int tl,int tr,int d) {
	if (l==tl&&r==tr) {
		cov[p]+=d;
		if (cov[p]) ret[p]=vy[r]^vy[l-1];
		else {
			if (l!=r) ret[p]=ret[p+p]^ret[p+p+1];
			else ret[p]=0;
		}
	} else {
		int md=(l+r)>>1;
		if (tr<=md) cover(p+p,l,md,tl,tr,d);
		else if (tl>md) cover(p+p+1,md+1,r,tl,tr,d);
		else cover(p+p,l,md,tl,md,d),cover(p+p+1,md+1,r,md+1,tr,d);
		if (cov[p]==0) ret[p]=ret[p+p]^ret[p+p+1];
	}
}
int solve() {
	rep(i,0,m) {
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		evt.pb((event){x1-1,1,y1-1,y2});
		evt.pb((event){x2,-1,y1-1,y2});
		vy.pb(y1-1); vy.pb(y2);
	}
	sort(all(evt),cmp);
	sort(all(vy));
	vy.erase(unique(all(vy)),vy.end());
	n=SZ(vy)-1;
	for (auto p:evt) {
		ans^=(p.x^prex)&ret[1]; prex=p.x;
		p.y1=lower_bound(all(vy),p.y1)-vy.begin();
		p.y2=lower_bound(all(vy),p.y2)-vy.begin();
		cover(1,1,n,p.y1+1,p.y2,p.ty);
	}
	return ans;
}
int main() {
	scanf("%*d%d%d",&m,&K);
	k=1; while (k<=K) k*=2;
	puts(solve()&(k-1)?"Hamed":"Malek"); 
}