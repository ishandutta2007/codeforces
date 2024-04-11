#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
template<class T>inline void ckmax(T &x,const T &y){if(x<y)x=y;}
template<class T>inline void ckmin(T &x,const T &y){if(x>y)x=y;}
typedef pair<int,int> pii;
#define fi first
#define se second
set<pair<int,pii> >ed;
set<pii>ex[maxn],l[maxn];
map<pii,int>val;
inline pii ord_pii(int x,int y){
	if(x>y)swap(x,y);
	return {x,y};
}
inline ll calc(){
	ll ret=(ll)ed.begin()->fi+next(ed.begin(),1)->fi+next(ed.begin(),2)->fi;
	vector<pair<int,pii> >tmp;
	ri cnt=0;
	for(auto i:ed){
		tmp.push_back(i);
		if(++cnt==6)break;
	}
	for(ri i=0;i<cnt;++i){
		for(ri j=i+1;j<cnt;++j)
			if(tmp[i].se.fi!=tmp[j].se.fi&&
			tmp[i].se.fi!=tmp[j].se.se&&
			tmp[i].se.se!=tmp[j].se.fi&&
			tmp[i].se.se!=tmp[j].se.se)
				ckmin(ret,(ll)tmp[i].fi+tmp[j].fi);
	}
	return ret;
}
inline void insertl(int p,pii v){
	if(l[v.se].find({v.fi,p})!=l[v.se].end())ed.insert({v.fi,ord_pii(p,v.se)});
	l[p].insert(v);
}
inline void erasel(int p,pii v){
	ed.erase({v.fi,ord_pii(p,v.se)});
	l[p].erase(v);
}
inline void check(int p){
	while(l[p].size()<3&&ex[p].size()){
		insertl(p,*ex[p].begin());
		ex[p].erase(ex[p].begin());
	}
	if(!ex[p].size())return;
	auto it=l[p].upper_bound(*ex[p].begin());
	while(it!=l[p].end()){
		ex[p].insert(*it);
		erasel(p,*it);
		insertl(p,*ex[p].begin());
		ex[p].erase(ex[p].begin());
		it=l[p].upper_bound(*ex[p].begin());
	}
}
inline void insert(int p,pii v){
	ex[p].insert(v);
	check(p);
}
inline void erase(int p,pii v){
	auto it=l[p].find(v);
	if(it!=l[p].end())erasel(p,*it);
	else ex[p].erase(v);
	check(p);
}
int m,n,q;
int main(){
	scanf("%d%d",&n,&m);
	while(m--){
		ri x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		insert(x,{z,y});
		insert(y,{z,x});
		val[ord_pii(x,y)]=z;
	}
	printf("%lld\n",calc());
	scanf("%d",&q);
	while(q--){
		ri op,x,y,z;
		scanf("%d%d%d",&op,&x,&y);
		if(op){
			scanf("%d",&z);
			insert(x,{z,y});
			insert(y,{z,x});
			val[ord_pii(x,y)]=z;
		}
		else{
			z=val[ord_pii(x,y)];
			erase(x,{z,y});
			erase(y,{z,x});
		}
		printf("%lld\n",calc());
	}
	return 0;
}