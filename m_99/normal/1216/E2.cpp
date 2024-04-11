#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((mod_x)%modulo)
#define Inf 1000000001

vector<long long> cnt(18,0);
vector<long long> mini(18,0);

char get(long long k){
	
	for(int j=0;j<18;j++){
		if(k>=cnt[j]){
			k -= cnt[j];
		}
		else{
			long long ans = mini[j];
			ans += k/j;
			k %= j;
			return to_string(ans)[k];
			break;
		}
	}
}

long long get_sum(long long fir,long long d,long long n){
	if(n<=0)return 0;
	return n*(d*(n-1) + 2*fir)/2;
}

long long get_sum(long long k){
	long long ret = 0;
	for(int i=1;i<18;i++){
		ret += get_sum(i,i,min(k,cnt[i]/i));
		k-=cnt[i]/i;
		if(k>0)ret += k*cnt[i];
		else break;
	}
	return ret;
}

int main(){
	
	
	cnt[0] = 0;cnt[1] = 9;
	
	for(int i=2;i<cnt.size();i++){
		cnt[i] = cnt[i-1]*10;
	}

	for(int i=0;i<cnt.size();i++){
		cnt[i] *= i;
	}
	
	
	mini[1] = 1;
	for(int i=2;i<mini.size();i++){
		mini[i] = mini[i-1]*10;
	}
	
	int Q;
	cin>>Q;
	
	for(int i=0;i<Q;i++){
		
		long long k;
		cin>>k;
		//cout<<get_sum(k)<<endl;
		//continue;
		k--;
		
		long long ng = 500000000;
		long long ok = 0;
		
		while(ng-ok>1){
			long long mid = (ng+ok)/2;
			if(k>=get_sum(mid))ok = mid;
			else ng = mid;
		}
		k -= get_sum(ok);
		//cout<<ok<<',';
		cout<<get(k)<<endl;
	}
	
    return 0;
}