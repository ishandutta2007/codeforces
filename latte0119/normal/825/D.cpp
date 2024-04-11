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

string S,T;

int cnt[26];
signed main(){
	cin>>S>>T;
	vint lis;
	rep(i,S.size()){
		if(S[i]=='?')lis.pb(i);
		else cnt[S[i]-'a']++;
	}
	for(int i=0;;i++){
		int k=T[i%T.size()]-'a';

		if(cnt[k])cnt[k]--;
		else{
			if(lis.size()){
				S[lis.back()]=k+'a';
				lis.pop_back();
			}
			else{
				break;
			}
		}
	}
	cout<<S<<endl;
}