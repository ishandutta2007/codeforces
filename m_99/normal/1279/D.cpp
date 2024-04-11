#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000000000000

//ab
int beki(int a,int b){
	int x = 1;
	while(b!=0){
		if(b&1){
			x=mod(x*a);
		}
		a=mod(a*a);
		b>>=1;
	}
	return x;
}

//a
int gyakugen(int a){
	return beki(a,modulo-2);
}

int main(){
	
	int n;
	cin>>n;
	
	vector<int> p(1000000,0);
	vector<int> cnt(1000000,0);
	
	int g = gyakugen(n);
	
	for(int i=0;i<n;i++){
		int k;
		scanf("%d",&k);
		for(int j=0;j<k;j++){
			int a;
			scanf("%d",&a);
			a--;
			cnt[a] ++;
			p[a] = mod(p[a] + mod(gyakugen(k) * g));
		}
	}
	
	int ans = 0;
	
	for(int i=0;i<p.size();i++){
		int P = mod(p[i] * cnt[i]);
		P = mod(P * g);
		ans = mod(ans + P);
	}
	
	cout<<ans<<endl;
	

    return 0;
}