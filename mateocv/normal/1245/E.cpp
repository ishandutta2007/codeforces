#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

ll h[10][10];
long double dp[10][10];

pair<ll,ll> sum(ll i, ll j, ll m){
	if(m==0)return {i,j};
	if(i&1){
		if(j!=9){
			return sum(i,j+1,m-1);
		}else{
			return sum(i-1,j,m-1);
		}
	}else{
		if(j!=0){
			return sum(i,j-1,m-1);
		}else{
			return sum(i-1,j,m-1);
		}
	}
}

long double f(ll i, ll j){
	long double &r=dp[i][j];
	if(r>=0)return r;
	if(i==0&&j==0){
		r=0; return r;
	}
	if(i==0&&j<=6){
		r=6; return r;
	}
	/*if(!b||i==0){
		r=1;
		fore(k,1,7){
			pair<ll,ll> s=sum(i,j,k);
			r+=((long double)1)/6*f(s.fst,s.snd,1);
		}
		return r;
	}*/
	r=1;
	fore(k,1,7){
		pair<ll,ll> s=sum(i,j,k);
		r+=((long double)1)/6*(min(f(s.fst,s.snd),f(s.fst-h[s.fst][s.snd],s.snd)));
	}
	return r;
}

int main(){FIN;
	fore(i,0,10){
		fore(j,0,10){
			cin>>h[i][j];
		}
	}
	mset(dp,-1); //?
	/*fore(i,0,10){
		cout<<"\n";
		fore(j,0,10){
			cout<<fixed<<setprecision(3)<<f(i,j)<<" ";
		}
	}*/
	cout<<fixed<<setprecision(10)<<f(9,0);
	/*fore(i,0,10){
		cout<<"\n";
		fore(j,0,10){
			cout<<fixed<<setprecision(3)<<f(i,j,1)<<" ";
		}
	}*/
	
	return 0;
}