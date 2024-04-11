#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

template<int64_t mod>struct ModInt{
	int64_t a;
	inline int64_t normalize(int64_t x){
		x%=mod;
		if(x<0)x+=mod;
		return x;
	}
	ModInt(const int64_t a=0):a(normalize(a)){}

	ModInt& operator+=(const ModInt &x){
		a+=x.a;
		if(a>=mod)a-=mod;
		return *this;
	}
	ModInt& operator-=(const ModInt &x){
		a-=x.a;
		if(a<0)a+=mod;
		return *this;
	}
	ModInt& operator*=(const ModInt &x){
		a=a*x.a%mod;
		return *this;
	}
	ModInt& operator/=(const ModInt &x){
		*this*=x.inv();
		return *this;
	}

	ModInt operator+(const ModInt x){return ModInt(*this)+=x;}
	ModInt operator-(const ModInt x){return ModInt(*this)-=x;}
	ModInt operator*(const ModInt x){return ModInt(*this)*=x;}
	ModInt operator/(const ModInt x){return ModInt(*this)/=x;}
	bool operator==(const ModInt x){return a==x.a;}
	bool operator!=(const ModInt x){return a!=x.a;}

	ModInt operator-(){return ModInt(0)-ModInt(*this);}
	ModInt pow(int64_t ex)const{
		int64_t x=a;
		int64_t res=1;
		while(ex){
			if(ex&1)res=res*x%mod;
			x=x*x%mod;
			ex>>=1;
		}
		return ModInt(res);
	}
	ModInt inv()const{return pow(mod-2);}
};
using mint=ModInt<998244353>;
int N;
vint A[2222];

mint fact[2222];
mint inv[2222];

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

mint dp[2222][2222];

signed main(){
	scanf("%lld",&N);
	rep(i,N){
		A[i].resize(N);
		rep(j,N)scanf("%lld",&A[i][j]),A[i][j]--;
	}

	fact[0]=mint(1);
	for(int i=1;i<2222;i++)fact[i]=fact[i-1]*i;
	inv[2222-1]=fact[2222-1].inv();
	for(int i=2222-2;i>=0;i--)inv[i]=inv[i+1]*(i+1);

	dp[0][0]=mint(1);
	for(int i=1;i<2222;i++){
		for(int j=0;j<=i;j++){
			mint tmp=fact[i-j]*fact[i]*inv[j]*inv[i-j];
			if(j&1)dp[i][0]-=tmp;
			else dp[i][0]+=tmp;
		}
	}
	for(int i=1;i<2222;i++){
		for(int j=1;j<=i;j++){
			dp[i][j]+=dp[i-1][j-1]*j;
			dp[i][j]+=dp[i-1][j]*(i-j);
		}
	}

	mint ans;
	for(int i=0;i<N;i++){
		BinaryIndexedTree bit(N);
		BinaryIndexedTree bit2(N);
		
		mint le;
		vint pre(N),cur(N),al(N);
		int num=0;
		if(i==0){
			for(int j=0;j<N;j++){
				le+=fact[N-1-j]*(A[i][j]-bit.sum(A[i][j]-1));
				bit.add(A[i][j],1);
			}
		}
		else{
			for(int j=0;j<N;j++){
				int tmp=bit2.sum(A[i][j]-1);
				int co=2*j-num;
				if(cur[A[i-1][j]])co++;
				le+=dp[N-1-j][j-co]*tmp;
				
				tmp=A[i][j]-bit.sum(A[i][j]-1)-tmp;
				if(A[i-1][j]<A[i][j]&&cur[A[i-1][j]]==0)tmp--;
				le+=dp[N-1-j][j-co+1]*tmp;

				if(pre[A[i][j]]){
					bit2.add(A[i][j],-1);
				}
				cur[A[i][j]]=1;
				if(cur[A[i-1][j]]==0){
					bit2.add(A[i-1][j],1);
				}
				pre[A[i-1][j]]=1;
				if(al[A[i][j]]==0){
					al[A[i][j]]=1;
					num++;
				}
				if(al[A[i-1][j]]==0){
					al[A[i-1][j]]=1;
					num++;
				}

				bit.add(A[i][j],1);
			}
		}
		ans+=le*dp[N][0].pow(N-1-i);
	}
	printf("%lld\n",ans.a);
	return 0;
}