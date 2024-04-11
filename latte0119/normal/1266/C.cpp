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

signed main(){
	int H,W;
	cin>>H>>W;

	if(H==1&&W==1){
		cout<<0<<endl;
		return 0;
	}

	if(W==1){
		rep(i,H){
			printf("%lld\n",i+2);
		}
		puts("");
		return 0;
	}

	rep(i,H){
		rep(j,W){
			int num=(i+1)*(H+j+1);
			if(j)printf(" ");
			printf("%lld",num);
		}
		puts("");
	}
	return 0;
}