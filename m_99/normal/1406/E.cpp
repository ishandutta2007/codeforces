#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define modulo N
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000000

int call_A(int t){
	cout<<"A "<<t<<endl;
	scanf("%d",&t);
	return t;
}

int call_B(int t){
	cout<<"B "<<t<<endl;
	scanf("%d",&t);
	return t;
}

int main(){
	int n;
	cin>>n;

	vector<int> minP(n+1,-1);
	vector<int> P;
	vector<int> cnt;
	for(int i=2;i<minP.size();i++){
		if(minP[i]==-1){
			P.push_back(i);
			cnt.push_back(0);
			for(int j=i;j<minP.size();j+=i){
				if(minP[j]!=-1)continue;
				minP[j] = i;
				cnt.back() ++;
			}
		}
	}
	
	vector<vector<int>> Ps;
	vector<vector<int>> cnts;
	vector<int> sum;
	
	rep(i,P.size()){
		if(Ps.size()==0 || Ps.back().size()==100){
			Ps.push_back({P[i]});
			sum.push_back(cnt[i]);
			cnts.push_back({cnt[i]});
		}
		else{
			Ps.back().push_back(P[i]);
			cnts.back().push_back(cnt[i]);
			sum.back() += cnt[i];
		}
	}
	
	vector<int> Cnt(Ps.size()+1,n);
	set<int> Y;
	rep(i,Ps.size()){
		rep(j,Ps[i].size()){
			int t = call_B(Ps[i][j]);
			if(t!=cnts[i][j])Y.insert(Ps[i][j]);
		}
		Cnt[i+1] = call_A(1);
	}
	rep(i,Ps.size()){
		if(Cnt[i] - Cnt[i+1] != sum[i]){
			rep(j,Ps[i].size()){
				if(call_A(Ps[i][j])>0)Y.insert(Ps[i][j]);
			}
			break;
		}
	}

	int ans = 1;
	for(auto i:Y){
		long long temp = i;
		while(true){
			if(call_A(temp)>0){
				ans *= i;
			}
			else break;
			temp *= i;
			if(temp>n)break;
		}
	}
	
	cout<<"C "<<ans<<endl;
	
    return 0;
}