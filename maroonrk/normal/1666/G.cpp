#include <bits/stdc++.h>
using namespace std;

using ll=long long;

#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define repn(i,n) rng(i, 1, n+1)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)

#define all(x) x.bg,x.ed
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define si(x) int(x.size())
#define a first
#define b second
using P=pair<int,int>;
constexpr int INF = 1000000000;

template<class T>
bool chmin(T &a, T b){ if(a > b){ a = b; return true;} return false;}
template<class T>
bool chmax(T &a, T b){ if(a < b){ a = b; return true;} return false;}

template<class t>using vc=vector<t>;

using pi=pair<int,int>;
using vi=vc<int>;
using d=long double;
constexpr int SZ = 100005;

int n, x[SZ], y[SZ], z[SZ];
int m, a[SZ], b[SZ], c[SZ];

d get_tri(int p, int q, int r){
	d L[3];
	rep(_, 3){
		d pq = (d)(x[p]-x[q])*(d)(x[p]-x[q]);
		pq += (d)(y[p]-y[q])*(d)(y[p]-y[q]);
		pq += (d)(z[p]-z[q])*(d)(z[p]-z[q]);
		L[_] = sqrt(pq);
		if(_ == 0) swap(q, r);
		else if(_ == 1) swap(p, r);
	}
	d hf = (L[0]+L[1]+L[2])/2;
	return sqrt(hf*(hf-L[0])*(hf-L[1])*(hf-L[2]));
}
vc<pair<int,array<d,3>>>tri_info(int p, int q, int r){
	vc<int>vec{p, q, r};
	P mn = mp(INF, INF), mx = mp(-INF, INF);
	for(auto a:vec){
		chmin(mn, mp(z[a], a));
		chmax(mx, mp(z[a], a));
	}
	int sum = p+q+r;
	p = mn.b; r = mx.b; q = sum-p-r;
	//z[p] min z[r] max z[q] middle
	d zdif = (d)(z[r]-z[p]);
	d all_area = get_tri(p, q, r);
	
	//cout << p << " " << q << " " << r << " " << all_area << endl;
	vc<pair<int, array<d,3>>>ret;
	array<d,3>rui;rep(i,3)rui[i]=0;
	if(z[q] != z[r]){
		d coef = (d)(z[r]-z[q]) * (z[r]-z[q]);
		d god = all_area * (d)(z[r]-z[q]) / zdif;
		array<d,3>ad;
		ad[0] = (d)(z[r])*z[r], ad[1] = -2.0L*(d)(z[r]), ad[2] = 1.0L;
		rep(i, 3) ad[i] *= god/coef;
		ret.eb(z[r], ad); rui = ad;
	}
	if(z[p] != z[q]){
		d coef = (d)(z[q]-z[p])*(z[q]-z[p]);
		d god = all_area * (d)(z[q]-z[p]) / zdif;
		array<d,3>ad;
		ad[0] = -(d)(z[p])*z[p], ad[1] = 2.0L*(d)(z[p]), ad[2] = -1.0L;
		rep(i, 3) ad[i] *= god/coef;
		ad[0] += all_area;
		rui = ad;
		if(ret.empty()) ret.eb(z[q], ad);
		else{
			auto p = ret.back().b;
			rep(i, 3) ad[i] -= p[i];
			ret.eb(z[q], ad);
		}
	}
	array<d,3>dd;
	dd[1]=dd[2]=0; dd[0]=all_area;
	rep(i,3)dd[i]-=rui[i];
	ret.eb(z[p], dd);
	return ret;
}

struct uf{
	int par[SZ], ran[SZ];
	array<d,3>now[SZ];
	void init(){
		rep(i, SZ){
			par[i] = i;
			ran[i] = 0;
			rep(j, 3) now[i][j] = 0.0L;
		}
	}
	int find(int x){
		if(x == par[x]) return x; else return par[x] = find(par[x]);
	}
	void unite(int x, int y){
		x = find(x), y = find(y);
		if(x == y) return;
		if(ran[x] < ran[y]){
			par[x] = y;
			rep(i, 3) now[y][i]+=now[x][i];
		}
		else{
			par[y] = x;
			if(ran[x]==ran[y])ran[x]++;
			rep(i,3) now[x][i]+=now[y][i];
		}
	}
	bool same(int x,int y){ return find(x) == find(y); }
}uf;

vc<pair<int,array<d,3>>>ev[1000005];
vc<int>query[1000005];
vc<P>conn[1000005];
vc<int>edge[SZ];
map<P, int>M;
int q,h[SZ],p[SZ];
bool used[SZ], fail[SZ];
d ans[SZ];
int wh[SZ];
void slv(){
	cin >> n;
	repn(i, n) cin >> x[i] >> y[i] >> z[i];
	cin >> m;
	repn(i, m){
		cin >> a[i] >> b[i] >> c[i];
		auto RR = tri_info(a[i], b[i], c[i]);
		/*rep(i, RR.size()){
			cout << RR[i].a << " ";
			rep(j, 3) cout << (RR[i].b)[j] << ' ';
			cout << endl;
		}*/
		
		for(auto ab:RR){
			ev[ab.a].eb(i, ab.b);
		}
		vc<int>vec{a[i],b[i],c[i]};
		wh[a[i]] = i;
		wh[b[i]] = i;
		wh[c[i]] = i;
		
		rep(_,3){
			int sm=vec[_],bg=vec[(_+1)%3];
			if(sm>bg)swap(sm,bg);
			if(M.find(mp(sm,bg)) != M.end()){
				edge[i].pb(M[mp(sm,bg)]);
				edge[M[mp(sm,bg)]].pb(i);
				conn[max(z[sm], z[bg])].eb(i, M[mp(sm, bg)]);
			}
			M[mp(sm,bg)] = i;
		}
	}
	repn(i, n) assert(wh[i]);
	cin>>q;
	repn(i, q) {
		cin >> h[i] >> p[i];
		query[h[i]].pb(i);
	}
	uf.init();
	for(int t=1000000;t>=0;t--){
		for(auto q:query[t]){
			int pos = p[q];
			if(t >= z[pos]) fail[q] = true;
			else{
				//cout << pos << " " << wh[pos] << endl;
				auto poly = uf.now[uf.find(wh[pos])];
				ans[q] += poly[0];
				ans[q] += poly[1] * (d)(t);
				ans[q] += poly[2] * (d)(t) * (d)(t);
			}
		}
		for(auto ab:conn[t]){
			uf.unite(ab.a, ab.b);
		}
		for(auto ab:ev[t]){
			int v = ab.a;
			auto pp = ab.b;
			v = uf.find(v);
			rep(i, 3) uf.now[v][i] += pp[i];
		}
	}
	repn(i, q){
		if(fail[i]) cout << "-1\n";
		else cout << ans[i] << '\n';
	}
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	int t;t=1;//cin>>t;
	rep(_,t)slv();
}