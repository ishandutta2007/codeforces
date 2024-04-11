#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

int N,Q;
int L[5555],R[5555];

int S[5555];

signed main(){
	scanf("%lld%lld",&N,&Q);
	rep(i,Q)scanf("%lld%lld",&L[i],&R[i]),L[i]--;

	rep(i,Q)S[L[i]]++,S[R[i]]--;
	rep(i,N)S[i+1]+=S[i];


	int ans=0;
	rep(i,Q){
		vint s(N);
		rep(j,N)s[j]=S[j];
		for(int j=L[i];j<R[i];j++)s[j]--;
		vint t(N);

		int cnt=0;
		rep(j,N){
			if(s[j]>1)cnt++;
			else if(s[j]==1)t[j]++;
		}
		rep(j,N-1)t[j+1]+=t[j];

		for(int j=i+1;j<Q;j++){
			int tmp=cnt;
			if(L[j]!=0)tmp+=t[L[j]-1];
			tmp+=t[N-1];
			tmp-=t[R[j]-1];
			chmax(ans,tmp);
		}
	}	
	cout<<ans<<endl;
}