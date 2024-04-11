#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,a,b) for(int i=(a);i<(b);i++)
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

struct Median{
	multiset<int>lo,hi;
	int sumlo,sumhi;


	Median():sumlo(0),sumhi(0){}

	void adjust(){
		while(lo.size()>hi.size()){
			int tmp=*lo.rbegin();
			lo.erase(lo.find(tmp));
			sumlo-=tmp;
			hi.insert(tmp);
			sumhi+=tmp;
		}

		while(hi.size()>lo.size()+1){
			int tmp=*hi.begin();
			hi.erase(hi.find(tmp));
			sumhi-=tmp;
			lo.insert(tmp);
			sumlo+=tmp;
		}
	}

	void add(int x){
		if(hi.size()==0||*hi.begin()<=x){
			hi.insert(x);
			sumhi+=x;
		}
		else{
			lo.insert(x);
			sumlo+=x;
		}
		adjust();
	}
	void del(int x){
		if(*hi.begin()<=x){
			hi.erase(hi.find(x));
			sumhi-=x;
		}
		else{
			lo.erase(lo.find(x));
			sumlo-=x;
		}
		adjust();
	}

	int getMedian(){
		return *hi.begin();
	}
	int calcDistSum(){
		int m=getMedian();
		return (sumhi-m*(int)hi.size())+(m*(int)lo.size()-sumlo);
	}
};

template<class T>
struct  BinaryIndexedTree{
    int n;
    vector<T>dat;

    BinaryIndexedTree(int n=0):n(n),dat(n+1){}

    void add(int k,T x){
        for(k++;k<=n;k+=k&-k)dat[k]+=x;
    }
    T sum(int k){
        T ret{};
        for(k++;k;k-=k&-k)ret+=dat[k];
        return ret;
    }
};

int N;
int P[222222];

signed main(){
    scanf("%lld",&N);
    rep(i,N)scanf("%lld",&P[i]),P[i]--;

    vint ord(N);iota(all(ord),0);
    sort(all(ord),[&](int i,int j){
        return P[i]<P[j];
    });


    int in=0;
    BinaryIndexedTree<int>bit(N+114);

    Median md;
    rep(i,N){
        int k=ord[i];
        in+=i-bit.sum(k);
        bit.add(k,1);

        md.add(k);

        int m=md.getMedian();
        int l;
        if(i&1){
            l=i/2+1;
        }
        else{
            l=i/2;
        }

        int ans=in;
        int to=m-l;
        ans+=md.sumhi-(i+1-l)*to-(i+1-l)*(i+l)/2;
        ans+=l*to-md.sumlo+l*(l-1)/2;
        if(i)printf(" ");
        printf("%lld",ans);
    }
    puts("");
    return 0;
}