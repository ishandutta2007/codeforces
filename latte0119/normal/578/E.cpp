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

string S;

int N;
int A[111111];

vector<int>lis[111111];

signed main(){
	cin>>S;
	N=S.size();
	rep(i,N)A[i]=S[i]=='R';

	vector<int>idx[2];
	rep(i,N){
		int v=A[i];
		if(idx[v^1].size()==0){
			idx[v].pb(i);
			lis[i].pb(i);
		}
		else{
			int u=idx[v^1].back();
			idx[v^1].pop_back();
			idx[v].pb(u);
			lis[u].pb(i);
		}
	}

	vector<int>RR,RL,LR,LL;
	for(auto k:idx[0]){
		if(A[k]==0)LL.pb(k);
		else RL.pb(k);
	}
	for(auto k:idx[1]){
		if(A[k]==0)LR.pb(k);
		else RR.pb(k);
	}

	if(RL.size()&&LR.size()){
		int rl=RL.back();RL.pop_back();
		int lr=LR.back();LR.pop_back();
		if(lis[rl].back()>lis[lr].back()){
			lis[lr].pb(lis[rl].back());
			lis[rl].pop_back();
		}
		else{
			lis[rl].pb(lis[lr].back());
			lis[lr].pop_back();
		}
		RR.pb(rl);
		LL.pb(lr);
	}

	if(RR.size()<LL.size()){
		swap(RR,LL);swap(LR,RL);
	}

	vector<int>tmp;
	rep(i,RR.size()){
		tmp.pb(RR[i]);
		if(LL.size()>i)tmp.pb(LL[i]);
	}

	vector<int>ans=RL;
	if(tmp.size())ans.pb(tmp[0]);
	rep(i,LR.size())ans.pb(LR[i]);
	for(int i=1;i<tmp.size();i++)ans.pb(tmp[i]);

	vector<int>trail;
	rep(i,ans.size())trail.insert(trail.end(),all(lis[ans[i]]));

	printf("%lld\n",(int)ans.size()-1);
	rep(i,N){
		if(i)printf(" ");
		printf("%lld",trail[i]+1);
	}
	puts("");
	return 0;
}