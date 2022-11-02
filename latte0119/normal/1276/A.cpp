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

char buf[222222];
string strin(){
	scanf("%s",buf);
	return buf;
}

void solve(){
	string S=strin();

	vint ans;
	int cur=0;
	while(cur<S.size()){
		if(cur+5<=S.size()&&S.substr(cur,5)=="twone"){
			ans.pb(cur+2);
			cur+=5;
			continue;
		}
		if(cur+3<=S.size()&&(S.substr(cur,3)=="one"||S.substr(cur,3)=="two")){
			ans.pb(cur+1);
			cur+=3;
			continue;
		}
		cur++;
	}
	printf("%lld\n",(int)ans.size());
	rep(i,ans.size()){
		if(i)printf(" ");
		printf("%lld",ans[i]+1);
	}
	puts("");
}

signed main(){
	int t;scanf("%lld",&t);
	while(t--)solve();
	return 0;
}