#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

bool cmp1(const pair<pair<ll,ll>,ll> &a, const pair<pair<ll,ll>,ll> &b){
	return a.snd>b.snd||(a.snd==b.snd&&a.fst<b.fst);
}

bool cmp2(const pair<pair<ll,ll>,ll> &a, const pair<pair<ll,ll>,ll> &b){
	return a.fst.fst*b.fst.snd<a.fst.snd*b.fst.fst||(a.fst.fst*b.fst.snd==a.fst.snd*b.fst.fst&&a.snd>b.snd);
}

bool cmp3(const pair<pair<ll,ll>,ll> &a, const pair<pair<ll,ll>,ll> &b){
	return a.fst.snd<b.fst.snd||(a.fst.snd==b.fst.snd&&a.fst.fst<b.fst.fst)||(a.fst.snd==b.fst.snd&&a.fst.fst==b.fst.fst&&a.fst<b.fst);
}

ll n;
vector<pair<pair<ll,ll>,ll>> v;
pair<pair<ll,ll>,ll> a[2020];

typedef double tc;
struct Line{tc m,h;};
struct CHT { // for minimum (for maximum just change the sign of lines)
	vector<Line> c;
	int pos=0;
	tc in(Line a, Line b){
		tc x=b.h-a.h,y=a.m-b.m;
		return x/y; // ==ceil(x/y)
	}
	void add(tc m, tc h){ // m's should be non increasing
		Line l=(Line){m,h};
		if(c.size()&&m==c.back().m){
			l.h=min(h,c.back().h);c.pop_back();if(pos)pos--;
		}
		while(c.size()>1&&in(c.back(),l)<=in(c[c.size()-2],c.back())){
			c.pop_back();if(pos)pos--;
		}
		c.pb(l);
	}
	inline bool fbin(tc x, int m){return in(c[m],c[m+1])>x;}
	tc eval(tc x){
		// O(log n) query:
		int s=0,e=c.size();
		while(e-s>1){int m=(s+e)/2;
			if(fbin(x,m-1))e=m;
			else s=m;
		}
		return c[s].m*x+c[s].h;
	}
};

CHT mini,maxi;

double calc(double d){
	//cout<<d<<" "<<maxi.eval(d)<<" "<<mini.eval(d)<<endl;
	return -maxi.eval(d)-mini.eval(d);
}

double ter(double l, double r){
	ll it=0;
	double res=min(calc(l),calc(r));
	while(it--){
		double m0=l+(r-l)/3;
		double m1=r-(r-l)/3;
		if(calc(m0)<calc(m1)){
			r=m1;
		}else{
			l=m0;
		}
	}
	res=min(res,calc((l+r)/2));
	return res;
}

int main(){FIN;
	cin>>n;
	fore(i,0,n)cin>>a[i].fst.fst>>a[i].fst.snd>>a[i].snd;
	sort(a,a+n,cmp1);
	ll tot=0;
	//cout<<"HOLAAAAAAAAAA"<<endl;
	fore(i,0,n){
		fore(j,0,i){
			if(a[j].snd!=a[i].snd){
				v.pb({{a[i].fst.snd-a[j].fst.fst,a[j].snd-a[i].snd},1});
				v.pb({{a[i].fst.fst-a[j].fst.snd,a[j].snd-a[i].snd},-1});
				tot++;
			}
		}
	}
	sort(ALL(v),cmp2);
	//for(auto i:v)cout<<i.fst.fst<<" "<<i.fst.snd<<" "<<i.snd<<"\n";
	ll va=tot;
	//cout<<"HOLAAAAAAAAAA"<<endl;
	//sort(a,a+n,cmp);
	//cout<<"HOLAAAAAAAAAA"<<endl;
	//reverse(a,a+n);
	//fore(i,0,n)cout<<a[i].fst.fst<<" "<<a[i].fst.snd<<" "<<a[i].snd<<endl;
	fore(i,0,n){
		mini.add(a[i].snd,a[i].fst.fst);
	}
	reverse(a,a+n);
	fore(i,0,n)maxi.add(-a[i].snd,-a[i].fst.snd);
	if(tot==0){
		cout<<fixed<<setprecision(9)<<calc(0)<<"\n";
		return 0;
	}
	double res=9e18;
	res=min(res,ter(-1e11,1.*v[0].fst.fst/v[0].fst.snd));
	//set<pair<ll,ll>> vis;
	//vis.insert(v[0].fst);
	fore(i,0,SZ(v)){
		va+=v[i].snd;
		if(va==tot){
			if(i+1<SZ(v)){
				//if(!vis.count(v[i].fst)||!vis.count(v[i+1].fst)){
					res=min(res,ter(1.*v[i].fst.fst/v[i].fst.snd,1.*v[i+1].fst.fst/v[i+1].fst.snd));
					//vis.insert(v[i].fst);
					//vis.insert(v[i+1].fst);
				//}
				if(i+1<SZ(v)&&v[i].fst.fst<0&&v[i+1].fst.fst>0)res=min(res,calc(0));
			}else{
				res=min(res,ter(1.*v[i].fst.fst/v[i].fst.snd,1e11));
			}
		}
	}
	cout<<fixed<<setprecision(9)<<res<<"\n";
	return 0;
}