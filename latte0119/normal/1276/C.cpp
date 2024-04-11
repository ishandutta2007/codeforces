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

int N;
int A[444444];

signed main(){
	scanf("%lld",&N);
	rep(i,N)scanf("%lld",&A[i]);

	map<int,int>cnt;
	rep(i,N)cnt[A[i]]++;

	vint lis;
	for(auto &p:cnt)lis.pb(p.se);
	sort(all(lis));

	vint acc(lis.size()+1);
	rep(i,lis.size())acc[i+1]=acc[i]+lis[i];

	int ma=0,w,h;
	for(int i=1;i<=N;i++){
		int k=upper_bound(all(lis),i)-lis.begin();
		int sum=0;
		sum+=acc[k];
		sum+=(lis.size()-k)*i;
		
		int j=sum/i;
		if(j<i)continue;
		if(i*j>ma){
			ma=i*j;
			w=i;
			h=j;
		}
	}

	
	vector<vint>vis(h,vint(w));
	vpint ord;
	rep(j,w){
		if(vis[0][j])continue;
		int y=0,x=j;
		while(!vis[y][x]){
			ord.eb(y,x);
			vis[y][x]=true;
			y=(y+1)%h;
			x=(x+1)%w;
		}
	}

	vector<vint>ans(h,vint(w));
	int cur=0;
	
	vpint tmp;
	for(auto &p:cnt)tmp.eb(p.se,p.fi);
	sort(all(tmp));
	reverse(all(tmp));
	for(auto &p:tmp){
		int val=p.se;
		int num=min(p.fi,w);
		chmin(num,h*w-cur);
		for(int i=cur;i<cur+num;i++){
			ans[ord[i].fi][ord[i].se]=val;
		}
		cur+=num;
	}
	/*
	assert(cur==h*w);

	rep(i,h){
		vint v=ans[i];
		sort(all(v));
		rep(j,w-1)if(v[j]==v[j+1])assert(0);
	}
	rep(j,w){
		vint v;
		rep(i,h)v.pb(ans[i][j]);
		sort(all(v));
		rep(i,h-1)if(v[i]==v[i+1])assert(0);
	}
	*/

	printf("%lld\n",h*w);
	printf("%lld %lld\n",h,w);
	rep(i,h){
		rep(j,w){
			if(j)printf(" ");
			printf("%lld",ans[i][j]);
		}
		puts("");
	}
	return 0;
}