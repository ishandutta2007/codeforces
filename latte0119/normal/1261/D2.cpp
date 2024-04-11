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

template<uint32_t mod>
struct ModInt{
	uint32_t a;
	ModInt& s(uint32_t vv){
		a=vv<mod?vv:vv-mod;
		return *this;
	}

    ModInt(int64_t x=0){s(x%mod+mod);}

	ModInt& operator+=(const ModInt &x){return s(a+x.a);}
	ModInt& operator-=(const ModInt &x){return s(a+mod-x.a);}
	ModInt& operator*=(const ModInt &x){
		a=uint64_t(a)*x.a%mod;
		return *this;
	}
	ModInt& operator/=(const ModInt &x){
		*this*=x.inv();
		return *this;
	}

	ModInt operator+(const ModInt &x)const{return ModInt(*this)+=x;}
	ModInt operator-(const ModInt &x)const{return ModInt(*this)-=x;}
	ModInt operator*(const ModInt &x)const{return ModInt(*this)*=x;}
	ModInt operator/(const ModInt &x)const{return ModInt(*this)/=x;}
	bool operator==(const ModInt &x)const{return a==x.a;}
	bool operator!=(const ModInt &x)const{return a!=x.a;}
	bool operator<(const ModInt &x)const{return a<x.a;}

	ModInt operator-()const{return ModInt()-*this;}
	ModInt pow(int64_t n)const{
		ModInt res(1),x(*this);
		while(n){
			if(n&1)res*=x;
			x*=x;
			n>>=1;
		}
		return res;
	}

    ModInt inv()const{return pow(mod-2);}
};

template<uint32_t mod>
istream& operator>>(istream& in,const ModInt<mod>& a){
	return (in>>a.a);
}
template<uint32_t mod>
ostream& operator<<(ostream& out,const ModInt<mod>& a){
	return (out<<a.a);
}
using mint=ModInt<998244353>;

template<class Mint,int32_t lg>
struct ModIntTable{
	int N;
	vector<Mint>facts,finvs,invs;
	ModIntTable():N(1<<lg),facts(N),finvs(N),invs(N){
		const uint32_t mod=Mint(-1).a+1;
		invs[1]=1;
		for(int i=2;i<N;i++)invs[i]=invs[mod%i]*(mod-mod/i);

		facts[0]=1;
		finvs[0]=1;
		for(int i=1;i<N;i++){
			facts[i]=facts[i-1]*i;
			finvs[i]=finvs[i-1]*invs[i];
		}
	}
	inline Mint fact(int n)const{return facts[n];}
	inline Mint finv(int n)const{return finvs[n];}
	inline Mint inv(int n)const{return invs[n];}
	inline Mint binom(int n,int k)const{return facts[n]*finvs[k]*finvs[n-k];}
};
ModIntTable<mint,19>mtable;

int N,K;
int H[2222222];


mint po1[222222];
mint po2[222222];
mint po3[222222];
signed main(){
    scanf("%lld%lld",&N,&K);
    rep(i,N)scanf("%lld",&H[i]),H[i]--;

    if(K==1){
        cout<<0<<endl;
        return 0;
    }

    po1[0]=po2[0]=po3[0]=1;
    for(int i=1;i<=N;i++){
        po1[i]=po1[i-1]*K;
        po2[i]=po2[i-1]*2;
        po3[i]=po3[i-1]*(K-2);
    }
    mint bs=1;
    int cnt=0;
    for(int i=0;i<N;i++){
        if(H[i]==H[(i+1)%N]){
            bs*=K;
        }
        else{
            cnt++;
        }
    }

    mint ans;
    for(int i=0;i<cnt;i++){
        int r=cnt-i;
        mint tmp=po2[r];
        if(r%2==0){
            tmp-=mtable.binom(r,r/2);         
        }

        tmp/=2;
        ans+=bs*po3[i]*tmp*mtable.binom(cnt,i);
    }
    cout<<ans<<endl;
    return 0;
}