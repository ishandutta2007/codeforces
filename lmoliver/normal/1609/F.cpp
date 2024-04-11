#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> V;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
#define R(N,S,E) for(int N=(int)(S);N>=(int)(E);N--)
#define D(N,E) for(int N=(int)(0);N<(int)(E);N++)
LL read(){LL x;scanf("%lld",&x);return x;}

const int N=1.1e6;
LL a[N];

struct BIT{
	LL a[N];
	void add(int x,int v){
		x++;
		for(;x<N;x+=x&-x)a[x]+=v;
	}
	LL query(int x){
		x++;
		LL ans=0;
		for(;x;x&=x-1)ans+=a[x];
		return ans;
	}
	void clear(){
		memset(a,0,sizeof(a));
	}
};
struct Tree{
	BIT a,b;
	void add(int l,int v){
		a.add(l,(LL)-l*v);
		b.add(l,v);
	}
	void add(int l,int r,int v){
		add(l,v);
		add(r,-v);
	}
	LL query(int r){
		return a.query(r)+b.query(r)*r;
	}
	LL query(int l,int r){
		return query(r)-query(l);
	}
	void clear(){
		a.clear();
		b.clear();
	}
}tr[2];

struct Command{
	int tp,t,l,r,w;
};

LL solve(const vector<Command> &v,int n){
	// cerr<<"solve"<<endl;
	D(i,2)tr[i].clear();
	LL ans=0;
	LL ins=0;
	auto it=v.begin();
	F(r,1,n){
		// cerr<<"r="<<r<<endl;
		while(it!=v.end()&&it->t==r){
			int tp=it->tp;
			// cerr<<tp<<" ["<<it->l<<","<<it->r<<"] w="<<it->w<<endl;
			ins+=tr[1^tp].query(it->l,it->r)*it->w;
			tr[tp].add(it->l,it->r,it->w);
			it++;
		}
		ans+=ins;
	}
	return ans;
}

typedef pair<LL,int> P;

int pc(LL x){
	return x?pc(x>>1)+(x&1):0;
}

int p[N];

int main(){
	int n=read();
	F(i,1,n)a[i]=read();
	F(i,1,n)p[i]=pc(a[i]);
	vector<P> mxs,mns;
	vector<Command> commands[65];
	mxs.push_back({LONG_LONG_MAX,0});
	mns.push_back({LONG_LONG_MIN,0});
	F(i,1,n){
		while(a[i]>=mxs.back().first){
			int s=mxs.back().second;
			// assert(s>=1);
			// assert(s<i);
			// assert(p[s]>=0);
			// assert(p[s]<=64);
			commands[p[s]].push_back({0,i,mxs.rbegin()[1].second,s,-1});
			mxs.pop_back();
		}
		commands[p[i]].push_back({0,i,mxs.back().second,i,1});
		mxs.push_back({a[i],i});

		while(a[i]<=mns.back().first){
			int s=mns.back().second;
			commands[p[s]].push_back({1,i,mns.rbegin()[1].second,s,-1});
			mns.pop_back();
		}
		commands[p[i]].push_back({1,i,mns.back().second,i,1});
		mns.push_back({a[i],i});
	}
	LL ans=0;
	F(i,0,64)ans+=solve(commands[i],n);
	printf("%lld\n",ans);
	return 0;
}