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

int H,W;
char fld[111][111];
char tmp[111][111];

bool check(){
	if(H%3)return false;
	int d=H/3;
	rep(i,H)rep(j,W){
		if(fld[i][j]!=fld[i/d*d][0])return false;
	}

	if(fld[0][0]==fld[d][0]||fld[d][0]==fld[2*d][0]||fld[2*d][0]==fld[0][0])return false;
	return true;
}

signed main(){
	cin>>H>>W;
	rep(i,H)cin>>fld[i];

	rep(t,2){
		if(check()){
			cout<<"YES"<<endl;
			return 0;
		}
		rep(i,H)rep(j,W)tmp[j][i]=fld[i][j];
		swap(W,H);
		rep(i,H)rep(j,W)fld[i][j]=tmp[i][j];
	}

	cout<<"NO"<<endl;
    return 0;
}