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


int N,K;
signed main(){
    cin>>N>>K;

    vint w(10);
    w[0]=1;
    w[1]=N;
    w[2]=N*(N-1)/2;
    w[3]=N*(N-1)*(N-2)/6;
    w[4]=N*(N-1)*(N-2)*(N-3)/24;

    vint u(10);
    u[0]=1;
    u[1]=0;
    u[2]=1;
    u[3]=2;
    u[4]=9;

    int ans=0;
    for(int i=0;i<=K;i++)ans+=w[i]*u[i];
    cout<<ans<<endl;
    return 0;
}