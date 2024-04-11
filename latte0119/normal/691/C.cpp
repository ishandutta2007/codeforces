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

signed main(){
	string S;cin>>S;
	if(find(all(S),'.')==S.end())S+=".0";

	int posd=find(all(S),'.')-S.begin();

	int poss;
	rep(i,S.size()){
		if(S[i]=='0')continue;
		if(S[i]=='.')continue;
		poss=i;
		break;
	}

	int e;
	if(poss<posd)e=posd-poss-1;
	else e=-(poss-posd);

	string T;
	for(int i=poss;i<S.size();i++){
		if(S[i]=='.')continue;
		T+=S[i];
	}

	while(T.back()=='0')T.pop_back();

	cout<<T[0];
	if(T.size()>1){
		cout<<"."<<T.substr(1);
	}
	if(e){
		cout<<"E"<<e;
	}
	cout<<endl;
	return 0;
}