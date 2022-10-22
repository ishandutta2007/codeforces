#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001

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
	
	rolling_hash(char c){
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
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		string s;
		cin>>s;
		vector<rolling_hash> R(n+1);
		rep(i,n){
			R[i+1] = rolling_hash(s[i]);
			R[i+1] = R[i] + R[i+1];
		}
		reverse(s.begin(),s.end());
		vector<rolling_hash> Rr(n+1);
		rep(i,n){
			Rr[i+1] = rolling_hash(s[i]);
			Rr[i+1] = Rr[i] + Rr[i+1];
		}
		reverse(s.begin(),s.end());
		int cnt = 0;
		int remain = 0;
		rep(i,n){
			int l = i;
			int S = 0;
			for(int j=l;j<n;j++){
				if(s[j]=='(')S++;
				else S--;
				if(S<0)S = Inf;
				if(S==0){
					cnt++;
					i = j;
					break;
				}
				auto x = R[j+1] - R[l];
				auto y = Rr[n-l] - Rr[n-(j+1)];
				if(j!=i && x==y){
					cnt++;
					i = j;
					break;
				}
				if(j==n-1){
					remain = j-l+1;
					i = j;
				}
			}
		}
		cout<<cnt<<' '<<remain<<endl;
		
	}
	
	return 0;
}