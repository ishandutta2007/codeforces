#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second

using vint=vector<int>;
using pint=pair<int,int>;
using vpint=vector<pint>;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

template<class A,class B>
ostream& operator<<(ostream& ost,const pair<A,B>&p){
    ost<<"{"<<p.first<<","<<p.second<<"}";
    return ost;
}

template<class T>
ostream& operator<<(ostream& ost,const vector<T>&v){
    ost<<"{";
    for(int i=0;i<v.size();i++){
        if(i)ost<<",";
        ost<<v[i];
    }
    ost<<"}";
    return ost;
}

inline int topbit(unsigned long long x){
    return x?63-__builtin_clzll(x):-1;
}

inline int popcount(unsigned long long x){
    return __builtin_popcountll(x);
}

inline int parity(unsigned long long x){
    return __builtin_parity(x);
}


struct F{
	int x1,x2,y1,y2,a,b;

};

struct UKU{
	vector<F>fs;

	vint ps;
	vint accA,accB;
	vint idxL,idxR;
	void add(F f){
		fs.pb(f);
	}

	inline int idx(int x){
		return upper_bound(all(ps),x)-ps.begin()-1;
	}

	void build(){
		for(auto &f:fs){
			ps.pb(f.x1);
			ps.pb(f.x2);
		}
		ps.pb(0);
		ps.pb(1000000000);
		sort(all(ps));
		ps.erase(unique(all(ps)),ps.end());
		accA.resize(ps.size());
		accB.resize(ps.size());
		for(auto &f:fs){
			f.x1=idx(f.x1);
			f.x2=idx(f.x2);
			accB[0]+=f.y1;
			accB[f.x1]-=f.y1;

			accA[f.x1]+=f.a;
			accB[f.x1]+=f.b;
			accA[f.x2]-=f.a;
			accB[f.x2]-=f.b;

			accB[f.x2]+=f.y2;
		}

		for(int i=0;i+1<ps.size();i++){
			accA[i+1]+=accA[i];
			accB[i+1]+=accB[i];
		}
	}

	int calc(int x,int realX){
		//cout<<fs.size()<<endl;
		//for(auto f:fs)cout<<ps[f.x1]<<" "<<ps[f.x2]<<" "<<f.y1<<" "<<f.a<<" "<<f.b<<" "<<f.y2<<endl;
		
//		int k=idx(x);
	//	cout<<ps<<endl;
	//	cout<<ps[k]<<endl;
		int a=accA[x];
		int b=accB[x];
		
	//	cout<<"a b "<<a<<" "<<b<<endl;
		return a*realX+b;
	}
};

inline void calcIndex(vint &p,vint &c,vint &idx){
	int cur=0;
	idx.resize(p.size());
	for(int i=0;i<p.size();i++){
		while(cur+1<c.size()&&c[cur+1]<=p[i])cur++;
		idx[i]=cur;
	}
}

struct segtree{
	static const int SEG=1<<17;

	vector<UKU>dat;
	segtree():dat(SEG*2){}
	
	void add(int k,F f){
		k+=SEG-1;
		while(true){
			dat[k].add(f);
			if(k==0)break;
			k=(k-1)/2;
		}
	}

	void build(int k=0,int l=0,int r=SEG){
		dat[k].build();
		if(l+1==r)return;
		build(k*2+1,l,(l+r)/2);
		build(k*2+2,(l+r)/2,r);
		calcIndex(dat[k].ps,dat[k*2+1].ps,dat[k].idxL);
		calcIndex(dat[k].ps,dat[k*2+2].ps,dat[k].idxR);
	}

	int query(int a,int b,int x,int realX,int k=0,int l=0,int r=SEG){
		if(r<=a||b<=l)return 0;
		if(a<=l&&r<=b){
			return dat[k].calc(x,realX);
		}
		return query(a,b,dat[k].idxL[x],realX,k*2+1,l,(l+r)/2)+query(a,b,dat[k].idxR[x],realX,k*2+2,(l+r)/2,r);
	}
};

int N;
F fs[111111];



signed main(){
	scanf("%lld",&N);
	rep(i,N){
		int x1,x2,y1,y2,a,b;
		scanf("%lld%lld%lld%lld%lld%lld",&x1,&x2,&y1,&a,&b,&y2);
		x1++;x2++;
		fs[i]={x1,x2,y1,y2,a,b};
	}

	segtree seg;
	rep(i,N)seg.add(i,fs[i]);
	seg.build();

	int last=0;
	int Q;scanf("%lld",&Q);
	while(Q--){
		int l,r,x;
		scanf("%lld%lld%lld",&l,&r,&x);
		l--;
		x=(x+last)%1000000000;
		int realX=x;
		x=seg.dat[0].idx(x);
		last=seg.query(l,r,x,realX);
		printf("%lld\n",last);
		
	}
    return 0;
}