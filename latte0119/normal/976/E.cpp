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

int N,A,B;

signed main(){
	cin>>N>>A>>B;
	vint H(N),D(N);

	vpint lis;
	rep(i,N){
		cin>>H[i]>>D[i];
		if(D[i]<H[i])lis.eb(H[i]-D[i],i);
	}


	sort(all(lis));reverse(all(lis));
	vint use(N);

	int sum=accumulate(all(D),0ll);
	for(int i=0;i<lis.size()&&i<B;i++){
		use[lis[i].se]=1;
		sum+=lis[i].fi;
	}

	int ans=sum;
	if(B){
		for(int i=0;i<N;i++){
			int val=sum;
			if(use[i]){
				val-=H[i]-D[i];
			}
			else if(lis.size()>=B){
				val-=lis[B-1].fi;
			}

			val-=D[i];
			val+=H[i]<<A;
			chmax(ans,val);
		}
	}
	cout<<ans<<endl;
	return 0;
}