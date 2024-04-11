#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

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

struct BinaryIndexedTree{
	int n;
	vector<int>dat;
	BinaryIndexedTree(int n=0):n(n){
		dat.resize(n+1);
	}
	void add(int k,int x){
		for(k++;k<=n;k+=k&-k)dat[k]+=x;
	}
	int sum(int k){
		int ret=0;
		for(k++;k;k-=k&-k)ret+=dat[k];
		return ret;
	}
};

int N;
int A[222222];

vint lis[222222];
int Q;
int K[222222],pos[222222];
signed main(){
    scanf("%lld",&N);
    rep(i,N)scanf("%lld",&A[i]);
    scanf("%lld",&Q);
    rep(i,Q)scanf("%lld%lld",&K[i],&pos[i]),pos[i]--;
    vint uku;
    rep(i,N)uku.pb(A[i]);
    sort(all(uku));uku.erase(unique(all(uku)),uku.end());
    rep(i,N)A[i]=lower_bound(all(uku),A[i])-uku.begin();

    rep(i,N)lis[A[i]].pb(i);

    int tmp=0;
    vint cnt(N);rep(i,N)cnt[A[i]]++;
    vpint ev;
    for(int i=N-1;i>=0;i--){
        tmp+=cnt[i];
        ev.eb(tmp,i);
    }

    rep(i,Q)ev.eb(K[i],i-1001001001);
    sort(all(ev));

    BinaryIndexedTree bit(222222);

    int now=N-1;
    int tot=0;

    vint ans(Q);
    for(auto &p:ev){
        if(p.se>=0){
            for(auto &k:lis[p.se])bit.add(k,1);
            tot+=lis[p.se].size();
            now--;
            continue;
        }

        int i=p.se+1001001001;
        int k=p.fi;
        int lb=0,ub=N;
        while(ub-lb>1){
            int mid=(ub+lb)/2;
            int num=bit.sum(mid-1);

            int ptr=lower_bound(all(lis[now]),mid)-lis[now].begin();
            num+=min(ptr,k-tot);
            if(num<=pos[i])lb=mid;
            else ub=mid;
        }
        ans[i]=lb;
    }

    rep(i,Q)printf("%lld\n",uku[A[ans[i]]]);
    return 0;
}