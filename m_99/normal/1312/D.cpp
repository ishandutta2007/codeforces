#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000001

//ab
int beki(int a,int b,int M = modulo){
	int x = 1;
	while(b!=0){
		if(b&1){
			x=((long long)x*a)%M;
		}
		a=((long long)a*a)%M;
		b>>=1;
	}
	return x;
}


//a
int gyakugen(int a){
	return beki(a,modulo-2);
}

struct combi{
	deque<int> kaijou;
	deque<int> kaijou_;
	
	combi(int n){
		kaijou.push_back(1);
		for(int i=1;i<=n;i++){
			kaijou.push_back(mod(kaijou[i-1]*i));
		}
		
		int b=gyakugen(kaijou[n]);
		
		kaijou_.push_front(b);
		for(int i=1;i<=n;i++){
			int k=n+1-i;
			kaijou_.push_front(mod(kaijou_[0]*k));
		}
	}
	
	int combination(int n,int r){
		if(r>n)return 0;
		int a = mod(kaijou[n]*kaijou_[r]);
		a=mod(a*kaijou_[n-r]);
		return a;
	}
	
	int junretsu(int a,int b){
		int x = mod(kaijou_[a]*kaijou_[b]);
		x=mod(x*kaijou[a+b]);
		return x;
	}
	
};

int main(){
	
	int n,m;
	cin>>n>>m;
	
	combi C(1000000);
	
	if(n==2){
		cout<<0<<endl;
		return 0;
	}
	
	int ans = 0;
	
	for(int i=1;i<=m;i++){
		int temp = mod(i-1);
		if(n>3)temp = mod(temp * C.combination(i-2,n-3));
		temp = mod(temp * beki(2,n-3));
		//cout<<i<<':'<<temp<<endl;
		ans = mod(ans + temp);
	}
	
	cout<<ans<<endl;
	
	
    return 0;
}