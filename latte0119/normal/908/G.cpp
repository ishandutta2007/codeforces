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

/*
GF(p)
inverse:O(log p) based on Fermat's little theorem (a^(p-1)=1 mod p)
*/

template<int32_t mod>
struct ModInt{
	int32_t a;
	inline int32_t normalize(int64_t x){
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
		a=(int64_t)a*x.a%mod;
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

template<int32_t mod>
istream& operator>>(istream& in,ModInt<mod>& a){
	return (in>>a.a);
}
template<int32_t mod>
ostream& operator<<(ostream& out,const ModInt<mod>& a){
	return (out<<a.a);
}

using mint=ModInt<1000000007>;

string S;
mint po[1111];

mint dp[777][777][2];

signed main(){
	po[0]=0;
	for(int i=1;i<1111;i++)po[i]=po[i-1]*10+1;
	cin>>S;


	mint ans=0;
	for(int i=1;i<10;i++){
		rep(i,777)rep(j,777)rep(k,2)dp[i][j][k]=0;
		dp[0][0][0]=1;
		for(int j=0;j<S.size();j++){
			for(int k=0;k<=j;k++){
				dp[j+1][k][1]+=dp[j][k][1]*(10-i);
				dp[j+1][k+1][1]+=dp[j][k][1]*i;

				int tmp=min(S[j]-'0'+0ll,i);
				dp[j+1][k+1][1]+=dp[j][k][0]*tmp;
				tmp=max(0ll,S[j]-'0'-i);
				dp[j+1][k][1]+=dp[j][k][0]*tmp;

				if(S[j]-'0'<i)dp[j+1][k+1][0]+=dp[j][k][0];
				else dp[j+1][k][0]+=dp[j][k][0];
			}
		}

		rep(j,S.size()){
			ans+=(po[S.size()-j])*(dp[S.size()][j][0]+dp[S.size()][j][1]);
		}
	}
	cout<<ans<<endl;
	return 0;
}