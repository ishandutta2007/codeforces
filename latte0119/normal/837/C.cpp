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

int ans;

int N;
int H,W;
int h[111],w[111];


void solve(){
	rep(i,N)for(int j=i+1;j<N;j++){
		rep(k,2){
			swap(h[i],w[i]);
			if(w[i]>W)continue;
			rep(l,2){
				swap(h[j],w[j]);
				if(w[j]>W)continue;
				if(h[i]+h[j]>H)continue;
				chmax(ans,h[i]*w[i]+h[j]*w[j]);
			}
		}
	}
}

signed main(){
	cin>>N>>H>>W;
	rep(i,N)cin>>h[i]>>w[i];

	rep(k,2){
		solve();
		swap(H,W);
	}
	cout<<ans<<endl;
    return 0;
}