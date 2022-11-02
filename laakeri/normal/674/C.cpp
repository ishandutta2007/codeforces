#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef double ld;

const ld isQuery=-1e18;
struct Line {
	ld m, b;
	int id;
	Line(ld m_, ld b_, int id_) : m(m_), b(b_), id(id_) {}
	mutable multiset<Line>::iterator it,e;
	const Line* succ() const {
		return next(it)==e ? 0 : &*next(it);
	}
	bool operator<(const Line& rhs) const {
		if (rhs.b!=isQuery) return m<rhs.m;
		const Line* s=succ();
		if (!s) return 0;
		ld x=rhs.m;
		return b-s->b<(s->m-m)*x;
	}
};
struct DynamicHull : public multiset<Line> {
	iterator ei = begin();
	bool bad(iterator y) {
		auto z=next(y);
		if (y==begin()) {
			if (z==end()) return 0;
			return y->m==z->m&&y->b<=z->b;
		}
		auto x=prev(y);
		if (z==end()) return y->m==x->m&&y->b<=x->b;
		return (x->b-y->b)*(z->m-y->m)>=(y->b-z->b)*(y->m-x->m);
	}
	void insertLine(ld m, ld b, int id) {
		auto y=insert(ei, {m, b, id});
		y->it=y;y->e=end();ei=y;
		if (bad(y)) {erase(y);return;}
		while (next(y)!=end()&&bad(next(y))) erase(next(y));
		while (y!=begin()&&bad(prev(y))) erase(prev(y));
	}
	pair<ld, int> getMax(ld x) {
		auto l=*lower_bound({x, isQuery, 0});
		return {l.m*x+l.b, l.id};
	}
};

const ld inf=1e36;
ld wt[202020];
int n,k;

int aa[202020];
ld a[202020];
ld st[202020];
ld st2[202020];

ld dp[202020];
int fr[202020];

int go(ld x){
	DynamicHull dh;
	for (int i=0;i<=n;i++){
		if (i>0){
			auto asd=dh.getMax(wt[i]);
			dp[i]=st[i]-asd.F+x;
			fr[i]=asd.S;
		}
		pair<ld, ld> nv={-st2[i], dp[i]+st2[i]*wt[i]-st[i]};
		dh.insertLine(-nv.F, -nv.S, i);
	}
	int us=0;
	int uu=n;
	while (uu>0){
		us++;
		uu=fr[uu];
	}
	return us;
}

int main(){
	scanf("%d %d", &n, &k);
	for (int i=1;i<=n;i++){
		scanf("%d", &aa[i]);
		a[i]=aa[i];
	}
	ld su=0;
	for (int i=1;i<=n;i++){
		wt[i]+=(ld)1/a[i];
		wt[i]+=wt[i-1];
		su+=a[i];
		st[i]+=su/a[i];
		st[i]+=st[i-1];
		st2[i]+=a[i];
		st2[i]+=st2[i-1];
	}
	dp[0]=0;
	ld v=1e20;
	ld mi=0;
	ld ma=1e16;
	cout<<setprecision(25);
	for (int i=0;i<60;i++){
		ld mid=(mi+ma)/2;
		int u=go(mid);
		if (u<=k){
			v=min(v, dp[n]-(ld)u*mid);
			ma=mid;
		}
		else{
			mi=mid;
		}
	}
	cout<<v<<endl;
}