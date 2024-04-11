#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

typedef ll tc;
const tc is_query=-(1LL<<62); // special value for query
struct Line {
	tc m,b;
	mutable multiset<Line>::iterator it,end;
	const Line* succ(multiset<Line>::iterator it) const {
		return (++it==end? NULL : &*it);}
	bool operator<(const Line& rhs) const {
		if(rhs.b!=is_query)return m<rhs.m;
		const Line *s=succ(it);
		if(!s)return 0;
		return b-s->b<(s->m-m)*rhs.m;
	}
};
struct HullDynamic : public multiset<Line> { // for maximum
	bool bad(iterator y){
		iterator z=next(y);
		if(y==begin()){
			if(z==end())return false;
			return y->m==z->m&&y->b<=z->b;
		}
		iterator x=prev(y);
		if(z==end())return y->m==x->m&&y->b<=x->b;
		return (x->b-y->b)*(z->m-y->m)>=(y->b-z->b)*(y->m-x->m);
	}
	iterator next(iterator y){return ++y;}
	iterator prev(iterator y){return --y;}
	void add(tc m, tc b){
		iterator y=insert((Line){m,b});
		y->it=y;y->end=end();
		if(bad(y)){erase(y);return;}
		while(next(y)!=end()&&bad(next(y)))erase(next(y));
		while(y!=begin()&&bad(prev(y)))erase(prev(y));
	}
	tc eval(tc x){
		Line l=*lower_bound((Line){x,is_query});
		return l.m*x+l.b;
	}
};

int n;
ll r;
ll a[200005];
ll sp[200005];
ll rp[200005];

int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%lld",a+i),rp[i+1]=rp[i]+(i+1)*a[i],sp[i+1]=sp[i]+a[i];
	r=rp[n];
	HullDynamic w;
	w.add(0,0);
	//printf(" %lld\n",r);
	for(int i=n-1;i>=0;--i){
		//printf(" %d %lld\n",i,rp[i]+a[i]*n+(sp[n]-sp[i+1])-w.eval(-a[i]));
		r=max(r,rp[n]+a[i]*(n-1-i)-(sp[n]-sp[i+1])+w.eval(-a[i]));
		w.add((n-i),(sp[n]-sp[i]));
	}
	w=HullDynamic();
	//w.add(0,0);
	fore(i,0,n){
		if(i)r=max(r,rp[n]+sp[i]-a[i]*(i+1)+w.eval(a[i]));
		w.add(i+1,-sp[i]);
	}
	printf("%lld\n",r);
	return 0;
}