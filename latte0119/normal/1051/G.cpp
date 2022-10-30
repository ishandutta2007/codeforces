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

struct MergingSegmentTree{
    static const int LG=18;
    static const int SEG=1<<LG;
    static const int OP=SEG;
    static const int SZ=OP*LG+1;

    int tail;
    vector<int>chl,chr,sz,sum,opt;
    MergingSegmentTree():tail(1),chl(SZ),chr(SZ),sz(SZ),sum(SZ),opt(SZ){}

    int build(int val,int l=0,int r=SEG){
        int k=tail++;
        sz[k]=1;
        sum[k]=val;
        opt[k]=0;
        if(l+1==r)return k;

        int m=(l+r)>>1;
        if(val<m)chl[k]=build(val,l,m);
        else chr[k]=build(val,m,r);
        return k;
    }
    int merge(int t1,int t2,int l=0,int r=SEG){
        if(t1&&t2);else return t1^t2;
        sum[t1]+=sum[t2];
        sz[t1]+=sz[t2];
        if(l+1==r){
            opt[t1]=sz[t1]*(sz[t1]-1)/2*l;
            return t1;
        }
        int m=(l+r)>>1;
        
        chl[t1]=merge(chl[t1],chl[t2],l,m);
        chr[t1]=merge(chr[t1],chr[t2],m,r);
        opt[t1]=opt[chl[t1]]+sz[chr[t1]]*sum[chl[t1]]+opt[chr[t1]];
        return t1;
    }
};

signed main(){
    set<pint>s;
    MergingSegmentTree seg;
    int N;scanf("%lld",&N);
    int ans=0;
    rep(i,N){
        int a,b;
        scanf("%lld%lld",&a,&b);
        int k=seg.build(b);
        auto it=s.lower_bound(pint(a+1,-1));
        
        if(it!=s.begin()){
            it--;
            if(it->fi+seg.sz[it->se]>=a){
                ans-=b*(a-it->fi);
                ans-=seg.opt[it->se];
                seg.merge(it->se,k);
                tie(a,k)=*it;
                ans+=seg.opt[k];
            }
            else{
                s.insert(pint(a,k));
            }
        }
        else{
            s.insert(pint(a,k));
        }

        while(true){
            it=s.lower_bound(pint(a+1,-1));
            if(it==s.end())break;
            if(a+seg.sz[k]>=it->fi){
                ans-=seg.sum[it->se]*(it->fi-a);
                ans-=seg.opt[k];
                ans-=seg.opt[it->se];
                seg.merge(k,it->se);
                ans+=seg.opt[k];
                s.erase(*it);
            }
            else break;
        }
        printf("%lld\n",ans);
    }
    return 0;
}