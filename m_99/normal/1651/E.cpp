#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 100000000000000000
int n;
long long get(long long nn){
	return nn * (nn+1) / 2;
}

long long get(set<int> &ok,set<int> &ng){
	int l = *ok.begin();
	int r = *ok.rbegin();
	//cout<<l<<','<<r<<endl;
	auto it = ng.lower_bound(l);
	if(it!=ng.end() && (*it)<=r)return 0;
	
	long long ret = 1LL;
	//cout<<'a'<<endl;
	if(it==ng.begin())ret *= l+1;
	else{
		it--;
		ret *= abs(l - (*it));
	}
	it = ng.upper_bound(r);
	if(it==ng.end())ret *= n-r;
	else ret *= abs(r-(*it));
	//cout<<ret<<endl;
	return ret;
	
}

int main(){
	
	//int n;
	cin>>n;
	
	vector<vector<int>> E(n*2);
	rep(i,n*2){
		int u,v;
		cin>>u>>v;
		u--;v--;
		E[u].push_back(v);
		E[v].push_back(u);
	}
	long long ans = 0LL;
	/*
	rep(i,n){
		for(int j=i;j<n;j++){
			for(int k=n;k<2*n;k++){
				for(int l=k;l<2*n;l++){
					rep(m,n){
						if(m>=i&&m<=j){
							if(E[m][0]>=k&&E[m][0]<=l)ans++;
							else if(E[m][1]>=k&&E[m][1]<=l)ans++;
						}
					}
				}
			}
		}
	}
	cout<<ans<<endl;
	*/
	ans = 0;
	rep(i,n){
		int x = E[i][0],y = E[i][1];
		if(x>y)swap(x,y);
		x -= n;
		y -= n;
		long long cur = get(n);
		cur -= get(i);
		cur -= get(n-1-i);
		long long temp = get(n);
		temp -= get(x);
		temp -= get(n-1-y);
		temp -= get(y-x-1);
		cur *= temp;
		ans += cur;
	}
	//cout<<ans<<endl;
	vector<bool> f(n*2,false);
	
	rep(i,n){
		if(f[i])continue;
		vector<int> t(1,i);
		f[i] = true;
		while(true){
			bool F = false;
			rep(j,E[t.back()].size()){
				int to = E[t.back()][j];
				if(f[to])continue;
				f[to] = true;
				t.push_back(to);
				F = true;
				break;
			}
			if(!F)break;
		}
		rep(j,t.size()/2){
			set<int> okA,okB,ngA,ngB;
			rep(k,t.size()){
				if(t[k]<n)okA.insert(t[k]);
				else okB.insert(t[k]-n);
			}
			ngB.insert(t[1]-n);
			okB.erase(t[1]-n);
			//cout<<get(okA,ngA)<<','<<get(okB,ngB)<<endl;
			ans -= get(okA,ngA) * get(okB,ngB);
			for(int k=2;k<t.size()-1;k++){
				if(t[k]<n){
					okA.erase(t[k]);
				}
				else{
					okB.erase(t[k]-n);
				}
				if(k%2==1){
					ngB.insert(t[k]-n);
					ans -= get(okA,ngA) * get(okB,ngB);
				//	cout<<get(okA,ngA)<<','<<get(okB,ngB)<<endl;
					ngB.erase(t[k]-n);
				}
			}
			t.push_back(t[0]);
			t.push_back(t[1]);
			rep(k,2)t.erase(t.begin());
		}
	}
			
	
	cout<<ans<<endl;
	
	
	return 0;
}