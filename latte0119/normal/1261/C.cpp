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

int H,W;
string fld[1111111];

vector<vint>acc;
vector<vint>f;
vector<vint>uku;
void cand(int T){
	rep(i,H)rep(j,W){
		if(i<=T||j<=T||i+T>=H||j+T>=W){
			f[i][j]=0;
			continue;
		}

		int sum=acc[i+T][j+T]-acc[i-T-1][j+T]-acc[i+T][j-T-1]+acc[i-T-1][j-T-1];
		if(sum!=(2*T+1)*(2*T+1))f[i][j]=0;
		else f[i][j]=1;
	}
}


bool burn(int T){
	rep(i,H)rep(j,W)uku[i][j]=0;
	rep(i,H)rep(j,W){
		if(!f[i][j])continue;
		uku[i-T][j-T]++;
		uku[i+T+1][j-T]--;
		uku[i-T][j+T+1]--;
		uku[i+T+1][j+T+1]++;
	}
	rep(i,H)rep(j,W)if(i+1<H)uku[i+1][j]+=uku[i][j];
	rep(i,H)rep(j,W)if(j+1<W)uku[i][j+1]+=uku[i][j];
	rep(i,H)rep(j,W){
		if(uku[i][j]&&fld[i][j]=='.')return false;
		if(uku[i][j]==0&&fld[i][j]=='X')return false;
	}
	return true;
}

signed main(){
	cin.tie(0);ios_base::sync_with_stdio(0);

	cin>>H>>W;
	fld[0]=string(W+2,'.');
	for(int i=1;i<=H;i++){
		cin>>fld[i];
		fld[i]="."+fld[i]+".";
	}
	fld[H+1]=string(W+2,'.');
	H+=2;W+=2;


	acc.resize(H,vint(W,0));
	rep(i,H)rep(j,W)acc[i][j]=fld[i][j]=='X';
	rep(i,H)rep(j,W){
		if(i+1<H)acc[i+1][j]+=acc[i][j];
	}

	rep(i,H)rep(j,W){
		if(j+1<W)acc[i][j+1]+=acc[i][j];
	}


	f.resize(H,vint(W,0));
	uku.resize(H,vint(W,0));
	int lb=0,ub=min(H,W);
	while(ub-lb>1){
		int mid=(ub+lb)/2;
		cand(mid);
		if(burn(mid))lb=mid;
		else ub=mid;
	}

	cout<<lb<<endl;
	cand(lb);
	for(int i=1;i+1<H;i++){
		string s(W-2,'.');
		for(int j=1;j+1<W;j++){
			if(f[i][j])s[j-1]='X';
		}
		cout<<s<<"\n";
	}
	return 0;
}