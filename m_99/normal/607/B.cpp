#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000

struct rolling_hash{
	vector<long long> h;
	vector<vector<long long>> t_hash;
	vector<vector<long long>> power;
	long long b;
	vector<int> t;
	
	rolling_hash(){
	}
	
	rolling_hash(vector<int> &T){
		h.push_back(998244353);h.push_back(1000000007);h.push_back(1000000009);
		t_hash.resize(h.size(),vector<long long>(T.size()+1,0));
		power.resize(h.size(),vector<long long>(T.size()+1,1));
		b = 1010101;
		t=T;
		
		for(int i=0;i<h.size();i++){
			for(int j=1;j<=t.size();j++){
				power[i][j] = (power[i][j-1] * b)%h[i];
			}
		}
		
		for(int i=0;i<h.size();i++){
			for(int j=1;j<=t.size();j++){
				t_hash[i][j] = ((t_hash[i][j-1]*b + (long long)t[j-1]))%h[i];
			}
		}
			
		
	}
	
	//[l,r)
	vector<long long> get(int l,int r){
		vector<long long> ret(h.size());
		for(int i=0;i<h.size();i++){
			ret[i] = t_hash[i][r] - (t_hash[i][l] * power[i][r-l]);
			if(ret[i]>=0)ret[i]%=h[i];
			else{
				ret[i] = (-ret[i]%h[i]);
				ret[i] = (h[i]-ret[i])%h[i];
			}
		}
		return ret;
	}
	
	vector<long long> connect(vector<long long> A,vector<long long> B,int B_len){
		vector<long long> ret(h.size());
		for(int i=0;i<h.size();i++){
			ret[i] = ((A[i]*power[i][B_len])+B[i])%h[i];
		}
		return ret;
	}

	
};


int n;
vector<int> c;
rolling_hash B1,B2;
int get(int l,int r){
	if(l==r)return 0;
	static vector<vector<int>> dp(505,vector<int>(505,Inf));
	if(dp[l][r]!=Inf)return dp[l][r];
	int ret = 1 + get(l+1,r);
	for(int i=l+1;i<r;i++){
		if(c[l]==c[i]){
			if(i!=l+1)ret = min(ret,get(l+1,i)+get(i+1,r));
			else ret = min(ret,get(l+1,i)+1+get(i+1,r));
		}
	}
	dp[l][r] = ret;
	return ret;
	
}

int main(){

	
	cin>>n;
	
	c.resize(n);
	
	for(int i=0;i<n;i++){
		cin>>c[i];
		c[i]+=19;
	}
	
	B1 = rolling_hash(c);
	reverse(c.begin(),c.end());
	B2 = rolling_hash(c);
	cout<<get(0,n)<<endl;

	return 0;
}