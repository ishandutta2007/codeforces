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

signed main(){
	int N,K;
	cin>>N>>K;


	vint lis;
	rep(i,K){
		bool ok=false;
		for(int j=2;j<=N;j++){
			if(N%j)continue;
			lis.pb(j);
			ok=true;
			N/=j;
			break;
		}
		if(!ok){
			cout<<-1<<endl;
			return 0;
		}
	}
	lis.back()*=N;
	rep(i,K){
		if(i)cout<<" ";
		cout<<lis[i];
	}cout<<endl;
	return 0;
}