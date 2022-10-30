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
int H[222222];

signed main(){
	scanf("%lld%lld",&N,&K);
	rep(i,N)scanf("%lld",&H[i]);
	sort(H,H+N);
	reverse(H,H+N);

	vint S(N+1);
	rep(i,N)S[i+1]=S[i]+H[i];

	int h=H[0];
	int cur=1;
	int ans=0;
	while(cur<N){
		int tmp=K/cur;
		if(h-tmp>=H[cur]){
			int num=(h-H[cur])/tmp;
			ans+=num;
			h-=num*tmp;
		}

		int nex=cur+1;
		while(nex<N){
			int cost=cur*(h-H[nex])+S[nex]-S[cur]-H[nex]*(nex-cur);
			if(cost<=K)nex++;
			else break;		
		}
		if(nex==N){
			if(H[N-1]!=h)ans++;
			break;
		}
		int lb=H[nex];
		int ub=H[cur];
		while(ub-lb>1){
			int mid=(ub+lb)/2;
			int cost=cur*(h-mid)+S[nex]-S[cur]-mid*(nex-cur);
			if(cost<=K)ub=mid;
			else lb=mid;
		}
		h=ub;
		ans++;
		cur=nex;

	}
	cout<<ans<<endl;
	return 0;
}