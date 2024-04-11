#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001
vector<int> ng = {-1};
vector<int> get(vector<int> a){
	vector<int> ans;
	int n = a.size();
		
	rep(i,n-2){
		int mini = Inf;
		for(int j=i;j<n;j++)mini = min(mini,a[j]);
		while(a[i]!=mini){
			int ind;
			for(int j=i;j<n;j++){
				if(a[j]==mini){
					ind = j;
					break;
				}
			}
			int t = max(ind-2,i);
			ans.push_back(t);
			swap(a[t+1],a[t+2]);
			swap(a[t],a[t+1]);
			
		}
	}
	
	vector<int> b = a;
	sort(b.begin(),b.end());
	
	if(a != b){
		return ng;
	}
	else{
		return ans;
	}
	
}

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		int n;
		scanf("%d",&n);
		vector<int> a(n);
		vector<vector<int>> t(500);
		rep(i,n){
			scanf("%d",&a[i]);
			a[i]--;
			t[a[i]].push_back(i);
		}
	
		int cur = 0;
		rep(i,t.size()){
			rep(j,t[i].size()){
				t[i][j] = cur;
				cur++;
			}
		}
		
		{
			vector<int> aa = a;
			vector tt = t;
			rep(i,aa.size()){
				int ind = aa[i];
				aa[i] = tt[ind].back();
				tt[ind].pop_back();
			}
			vector<int> ans = get(aa);
			if(ans!=ng){
				cout<<ans.size()<<endl;
				rep(i,ans.size()){
					if(i!=0)cout<<' ';
					cout<<ans[i]+1;
				}
				cout<<endl;
				continue;
			}
		}
		
		{
			vector<int> aa = a;
			vector tt = t;
			rep(i,tt.size()){
				if(tt[i].size() >= 2){
					swap(tt[i][0],tt[i][1]);
					break;
				}
			}
			rep(i,aa.size()){
				int ind = aa[i];
				aa[i] = tt[ind].back();
				tt[ind].pop_back();
			}
			vector<int> ans = get(aa);
			if(ans!=ng){
				cout<<ans.size()<<endl;
				rep(i,ans.size()){
					if(i!=0)cout<<' ';
					cout<<ans[i]+1;
				}
				cout<<endl;
				continue;
			}
		}
		
		
		cout<<-1<<endl;
	}
	
	return 0;
}