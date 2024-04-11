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

int N;
template<class T>
inline void FastZetaTransformSuperset(vector<T>&f,function<T(T,T)>add){
    int n=__lg(f.size());
    for(int i=0;i<n;i++){
        for(int j=0;j<1<<n;j++){
            if(~j>>i&1)f[j]=add(f[j],f[j|1<<i]);
        }
    }
}


signed main(){
	cin>>N;
	vint f(1<<24);
	rep(i,N){
		string s;cin>>s;
		int m=0;
		rep(j,3)m|=1<<(s[j]-'a');
		m^=(1<<24)-1;
		f[m]++;
	}

	function<int(int,int)>ad=[](int a,int b){return a+b;};
	FastZetaTransformSuperset(f,ad);


	int ans=0;
	rep(i,1<<24){
		ans^=(N-f[i])*(N-f[i]);
	}
	cout<<ans<<endl;
	return 0;
}