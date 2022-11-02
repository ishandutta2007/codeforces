
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

char fld[11][11];

int dx[]={1,0,1,-1};
int dy[]={0,1,1,1};

bool check(){
	rep(i,10)rep(j,10){
		rep(d,4){
			bool ok=true;
			for(int k=0;k<5;k++){
				int y=i+dy[d]*k;
				int x=j+dx[d]*k;
				if(y<0||y>=10||x<0||x>=10||fld[y][x]!='X')ok=false;
			}
			if(ok)return true;
		}
	}
	return false;
}

signed main(){
	rep(i,10)cin>>fld[i];

	rep(i,10)rep(j,10){
		if(fld[i][j]!='.')continue;
		fld[i][j]='X';
		if(check()){
			cout<<"YES"<<endl;
			return 0;
		}

		fld[i][j]='.';
	}

	cout<<"NO"<<endl;
    return 0;
}