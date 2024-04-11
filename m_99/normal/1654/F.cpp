#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001

int main(){
	
	int n;
	cin>>n;
	string s;
	cin>>s;
	
	string AA;
	int nn = (n+1)/2;
	rep(i,1<<nn){
		string t(1<<n,'0');
		rep(j,s.size()){
			t[j] = s[j^i];
		}
		vector<string> ss;
		rep(j,1<<(n-nn)){
			ss.push_back(t.substr(j * (1<<nn), 1<<nn));
		}
		auto tt = ss;
		sort(tt.begin(),tt.end());
		tt.erase(unique(tt.begin(),tt.end()),tt.end());
		vector<int> ind(ss.size());
		rep(j,ss.size()){
			ind[j] = distance(tt.begin(),lower_bound(tt.begin(),tt.end(),ss[j]));
		}
		vector<int> ans;
		rep(j,ind.size()){
			vector<int> temp(ind.size());
			rep(k,ind.size()){
				temp[k] = ind[j^k];
			}
			if(j==0 || ans>temp)ans = temp;
		}
		string Ans = "";
		rep(j,ans.size()){
			Ans += tt[ans[j]];
		}
		if(i==0 || AA>Ans)AA = Ans;
		
	}
	assert(AA.size()==(1<<n));
	cout<<AA<<endl;
	
	return 0;
}