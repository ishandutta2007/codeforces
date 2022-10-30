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


int N,M;
int A[44];

vint calc(int l,int r){
    vint v;
    int n=r-l;
    rep(i,1<<n){
        int val=0;
        rep(j,n)if(i>>j&1)val=(val+A[l+j])%M;
        v.pb(val);
    }

    return v;
}

signed main(){
    cin>>N>>M;
    rep(i,N)cin>>A[i];

    int n1=N/2;
    int n2=N-n1;

    auto v1=calc(0,n1);
    auto v2=calc(n1,N);

    int ans=0;

    sort(all(v2));
    for(auto a:v1){
        auto it=lower_bound(all(v2),M-a);
        if(it!=v2.begin()){
            it--;
            chmax(ans,*it+a);
        }

        chmax(ans,(a+v2.back())%M);
    }
    cout<<ans<<endl;
    return 0;
}