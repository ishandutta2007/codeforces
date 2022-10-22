#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000000000000

struct rolling_hash{

	long long t_hash;
	static vector<long long> power;
	static const long long MOD = (1LL<<61)-1;
	static const long long b = 123456;
	int sz;
	
	rolling_hash(){		
		sz = 0;
		t_hash = 0;
	}
	
	rolling_hash(long long c){
		sz = 1;
		t_hash = b*c;
	}

	long long mul(__int128 x,__int128 y){
		__int128 t = x*y;
		t = (t>>61) + (t&MOD);
		
		if(t>=MOD)t -= MOD;
		return t;
	}
	
	long long get_pow(int sz){
		if(power.size()>sz)return power[sz];
		
		while(power.size()<=sz){
			if(power.size()==0)power.push_back(1);
			else power.push_back(mul(power.back(),b));
		}
		return power.back();
		
	}
	
	rolling_hash &operator+=(const rolling_hash &another){
		
		(*this).t_hash = mul((*this).t_hash,get_pow(another.sz));
		(*this).t_hash += another.t_hash;
		if((*this).t_hash>=MOD)(*this).t_hash -= MOD;
			
		(*this).sz += another.sz;
		
		return (*this);
	}
	
	rolling_hash operator+(const rolling_hash &another)const{
		return (rolling_hash(*this)+=another);
	}
	
	rolling_hash &operator-=(const rolling_hash &another){

		(*this).t_hash += MOD - mul(another.t_hash,get_pow((*this).sz-another.sz));
		if((*this).t_hash>=MOD)(*this).t_hash -= MOD;
			
		(*this).sz -= another.sz;

		return (*this);
	}
	
	rolling_hash operator-(const rolling_hash &another)const{
		return (rolling_hash(*this)-=another);
	}
	
	bool operator<(const rolling_hash &another)const{
		if((*this).t_hash!=another.t_hash)return (*this).t_hash<another.t_hash;
		return (*this).sz<another.sz;
	}
	
	bool operator==(const rolling_hash &another)const{
		return ((*this).t_hash==another.t_hash && (*this).sz==another.sz);
	}

	
};

vector<long long> rolling_hash::power;

long long ans = 0LL;
int n;

void dfs(vector<int> &a,int l,int r){
	
	if(r-l<=1)return;
	
	int mid = (l+r)/2;
	vector<int> cur;
	vector<int> pre(1,0);
	vector<rolling_hash> R(1);
	for(int i=mid;i<r;i++){
		rolling_hash r = R[pre.back()];
		if(cur.size()==0 || cur.back()!=a[i]){
			cur.push_back(a[i]);
			pre.push_back(R.size());
			r += rolling_hash(a[i]);
			R.push_back(r);
		}
		else{
			cur.pop_back();
			pre.pop_back();
			R.push_back(R[pre.back()]);
		}
	}
			
	sort(R.begin(),R.end());
	R.erase(R.begin());

	cur.resize(0);
	pre.assign(1,0);
	vector<rolling_hash> RR(1);
	long long t = 0LL;
	//ans += distance(lower_bound(R.begin(),R.end(),r),upper_bound(R.begin(),R.end(),RR[0]));
	//t += distance(lower_bound(R.begin(),R.end(),r),upper_bound(R.begin(),R.end(),RR[0]));
	for(int i=mid-1;i>=l;i--){
		rolling_hash r = RR[pre.back()];
		if(cur.size()==0 || cur.back()!=a[i]){
			cur.push_back(a[i]);
			pre.push_back(RR.size());
			r += rolling_hash(a[i]);
			RR.push_back(r);
		}
		else{
			cur.pop_back();
			pre.pop_back();
			RR.push_back(RR[pre.back()]);
		}
		ans += distance(lower_bound(R.begin(),R.end(),RR.back()),upper_bound(R.begin(),R.end(),RR.back()));
		t += distance(lower_bound(R.begin(),R.end(),RR.back()),upper_bound(R.begin(),R.end(),RR.back()));
		
	}
	
//	cout<<l<<','<<r<<','<<t<<endl;
	
	dfs(a,l,mid);
	dfs(a,mid,r);
	
}

int main(){
	
	int _t;
	cin>>_t;
	
	
	rep(_,_t){
		
		
		scanf("%d",&n);
		vector<int> a(n);
		rep(i,n){
			scanf("%d",&a[i]);
			a[i]+=8;
		}
		ans = 0LL;
		
		dfs(a,0,n);
		printf("%lld\n",ans);
	}
	
    return 0;
}