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

int main(){
	
	int n,m;
	scanf("%d %d",&n,&m);
	
	vector<vector<int>> A(n,vector<int>(m)),B(n,vector<int>(m));
	vector<rolling_hash> R(n);
	rep(i,n){
		rep(j,m){
			scanf("%d",&A[i][j]);
			A[i][j] += 9;
		}
		rolling_hash r;
		rep(j,m){
			r += rolling_hash(A[i][j]);
		}
		R[i] = r;
	}
	
	
	
	rep(i,n){
		rep(j,m){
			scanf("%d",&B[i][j]);
			B[i][j] += 9;
		}
	}
	
	vector<int> t(n,-1);
	
	rep(i,n){
		rolling_hash r;
		rep(j,m){
			r += rolling_hash(B[i][j]);
		}
		
		bool f = false;
		rep(j,n){
			if(R[j]==r){
				R[j] = rolling_hash();
				t[i] = j;
				f=true;
				break;
			}
		}
		if(!f){
			cout<<-1<<endl;
			return 0;
		}
	}
	vector<bool> need(n-1,false);
	vector<vector<int>> oks(m),ngs(n-1);
	vector<int> ng_cnt(m,0);
	vector<bool> released(n-1,false);
	rep(i,n-1){
		if(t[i]>t[i+1]){
			need[i] = true;
		}
		rep(j,m){
			if(A[t[i]][j]<A[t[i+1]][j]){
				oks[j].push_back(i);
			}
			if(A[t[i]][j]>A[t[i+1]][j]){
				ngs[i].push_back(j);
				ng_cnt[j]++;
			}
		}		
	}
	vector<int> ans;
	queue<int> Q;
	rep(i,m){
		if(ng_cnt[i]==0){
			Q.push(i);
			ng_cnt[i] = -1;
		}
	}
	while(Q.size()>0){
		int u = Q.front();
		Q.pop();
		ans.push_back(u);
		rep(i,oks[u].size()){
			int v = oks[u][i];
			if(!released[v]){
				released[v] = true;
				rep(j,ngs[v].size()){
					int x = ngs[v][j];
					ng_cnt[x]--;
					if(ng_cnt[x]==0){
						ng_cnt[x] = -1;
						Q.push(x);
					}
				}
			}
		}		
	}
	
	rep(i,n-1){
		if(need[i]&&!released[i]){
			printf("-1\n");
			return 0;
		}
	}
	
	reverse(ans.begin(),ans.end());
	
	cout<<ans.size()<<endl;
	rep(i,ans.size()){
		if(i!=0)printf(" ");
		printf("%d",ans[i]+1);
	}
	cout<<endl;
	
	
	
	
    return 0;
}