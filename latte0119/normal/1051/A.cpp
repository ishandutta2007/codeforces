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

string uku="*aA0";

bool check(string s){
	bool f1=false,f2=false,f3=false;
	rep(i,s.size()){
		if(isdigit(s[i]))f1=true;
		if(islower(s[i]))f2=true;
		if(isupper(s[i]))f3=true;
	}
	return f1&&f2&&f3;
}

void solve(){
	string s;cin>>s;

	rep(m,4)for(int l=m;l<4;l++){
		int i=m;
		int j=l;
		string ss=s;
		if(i)ss[0]=uku[i];
		if(j)ss[1]=uku[j];
		if(check(ss)){
			cout<<ss<<endl;
			return;
		}

		i=l;
		j=m;
		ss=s;
		if(i)ss[0]=uku[i];
		if(j)ss[1]=uku[j];
		if(check(ss)){
			cout<<ss<<endl;
			return;
		}
	}
}

signed main(){
	int T;cin>>T;
	while(T--)solve();
}