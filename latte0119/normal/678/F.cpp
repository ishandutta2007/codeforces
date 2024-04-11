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

const int INF=1001001001001001001ll;
struct ConvexHullTrick{
#define a first
#define b second
	using Line=pair<signed,signed>;
	vector<Line>lines;
 
	//l.a>=m.a>=r.a
	inline bool needless(const Line &l,const Line &m,const Line &r){
		return (int)(m.a-l.a)*(r.b-m.b)>=(int)(m.b-l.b)*(r.a-m.a);
	}
	void addLine(signed a,signed b){
		a*=-1,b*=-1;
		Line l(a,b);
		if(lines.empty())lines.push_back(l);
		else{
			if(lines.back().a==a){
				if(lines.back().b<=b)return;
				lines.pop_back();
			}
			while(lines.size()>=2&&needless(lines[lines.size()-2],lines[lines.size()-1],l))lines.pop_back();
			lines.push_back(l);
		}
	}
 
	inline int eval(const Line &l,signed x){
		return (int)l.a*x+l.b;
	}

	int queryMonotoneDec(signed x){
		while(lines.size()>=2&&eval(lines[lines.size()-1],x)>=eval(lines[lines.size()-2],x))lines.pop_back();
		return -eval(lines.back(),x);
	}

#undef a
#undef b
};
using CHT=ConvexHullTrick;


const signed SEG=1<<19;
CHT dat[SEG*2];

void add(signed a,signed b,pint L,signed k=0,signed l=0,signed r=SEG){
	if(r<=a||b<=l)return;
	if(a<=l&&r<=b){
		dat[k].addLine(L.fi,L.se);
		return;
	}

	add(a,b,L,k*2+1,l,(l+r)/2);
	add(a,b,L,k*2+2,(l+r)/2,r);
}

int query(signed k,signed x){
	k+=SEG-1;
	int ret=-INF;
	while(true){
		if(dat[k].lines.size())chmax(ret,dat[k].queryMonotoneDec(x));
		if(k==0)break;
		k=(k-1)/2;
	}
	return ret;
}

signed N;
signed T[333333],A[333333],B[333333];

signed ft[333333];
int ans[333333];
signed main(){
	scanf("%d",&N);
	rep(i,N){
		scanf("%d",&T[i]);
		if(T[i]==1)scanf("%d%d",&A[i],&B[i]);
		else scanf("%d",&A[i]);
	}

	vector<tuple<signed,signed,signed,signed>>qadd;
	memset(ft,-1,sizeof(ft));
	rep(i,N){
		if(T[i]==2){
			ft[A[i]-1]=i;
		}
	}


	rep(i,N){
		if(T[i]==1){
			int r;
			if(ft[i]!=-1)r=ft[i];
			else r=N;

			qadd.eb(A[i],B[i],i,r);
		}
	}

	sort(all(qadd));

	for(auto &t:qadd){
		signed a,b,l,r;
		tie(a,b,l,r)=t;
		add(l,r,pint(a,b));
	}

	vector<tuple<signed,signed>>qeval;
	rep(i,N){
		if(T[i]==3){
			qeval.eb(A[i],i);
		}
	}

	sort(all(qeval));
	reverse(all(qeval));
	for(auto &t:qeval){
		signed q,k;
		tie(q,k)=t;
		ans[k]=query(k,q);
	}

	rep(i,N){
		if(T[i]!=3)continue;
		if(ans[i]==-INF)puts("EMPTY SET");
		else printf("%lld\n",ans[i]);
	}
	return 0;
}