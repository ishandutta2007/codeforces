#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n,l,r,s;
		cin>>n>>l>>r>>s;
		
		vector<int> ans(r-l+1);
		rep(i,ans.size()){
			ans[i] = i+1;
			s -= i+1;
		}
		if(s<0){
			cout<<-1<<endl;
			continue;
		}
		
		vector<int> temp;
		temp.push_back(n+1);
		while(s!=0&&ans.size()!=0){
			if(ans.back()+1 < temp.back()){
				ans.back()++;
				s--;
			}
			else{
				temp.push_back(ans.back());
				ans.pop_back();
			}
		}
		if(s!=0){
			cout<<-1<<endl;
			continue;
		}
		while(temp.size()!=1){
			ans.push_back(temp.back());
			temp.pop_back();
		}
		set<int> S;
		rep(i,n)S.insert(i+1);
		vector<int> Put(n,-1);
		rep(i,ans.size()){
			Put[l-1+i] = ans[i];
			S.erase(ans[i]);
		}
		rep(i,n){
			if(Put[i]==-1){
				Put[i] = *S.begin();
				S.erase(S.begin());
			}
		}
		
		rep(i,n){
			if(i!=0)cout<<' ';
			cout<<Put[i];
		}
		cout<<endl;
		
		
	}
	
	return 0;
}