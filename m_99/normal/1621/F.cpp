#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000000

long long ans;
long long a,b,c;

void dfs(int l,int r,vector<int> &v,int c1,int c101,int cur,long long cv = 0){
	ans = max(ans,cv);
	if(cur==0){
		if(v.size()>0){
			if(c1==0&&c101>0){
				dfs(l,r,v,c1+1,c101-1,1,cv-c);
			}
			auto X = v.back();
			v.pop_back();
			X--;
			if(X==1){
				dfs(l,r,v,c1,c101+1,1,cv+a);
				v.push_back(X);
			}
			else{
				v.push_back(X);
				dfs(l,r,v,c1,c101,1,cv+a);
				v.back()++;
			}
			
			
			return;
		}
		else{
			if(l>r)swap(l,r);
			if(r>=2){
				dfs(l,r-1,v,c1,c101,1,cv+a);
				if(c1==0&&c101>0){
					dfs(l,r,v,c1+1,c101-1,1,cv-c);
				}
			}
			else{
				if(c101>0){
					dfs(l,r,v,c1+1,c101-1,1,cv-c);
				}
				else{
					if(r==1){
						dfs(l,r-1,v,c1,c101,1,cv-c);
					}
				}
			}
		}
		
	}
	else{
		if(c1>0){
			dfs(l,r,v,c1-1,c101,0,cv+b);
		}
	}
	
}

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		int n;
		cin>>n;
		ans = 0;
		cin>>a>>b>>c;
		
		string s;
		cin>>s;
		
		rep(ii,2){
			vector<pair<int,int>> p;
			rep(i,s.size()){
				if(p.size()==0 || p.back().first!=s[i]-'0'){
					p.emplace_back(s[i]-'0',1);
				}
				else p.back().second++;
			}
			/*
			rep(i,p.size()){
				cout<<p[i].first<<','<<p[i].second<<endl;
			}
			*/
			int l=0,r=0;
			
			if(p[0].first==0){
				l = p[0].second;
				p.erase(p.begin());
			}
			if(p.size()>0&&p.back().first==0){
				r = p.back().second;
				p.pop_back();
			}
			
			vector<int> x;
			int c1 = 0;
			int c101 = 0;
			rep(i,p.size()){
				if(p[i].first==0){
					if(p[i].second==1){
						c101 ++;
					}
					else{
						x.push_back(p[i].second);
					}
				}
				else{
					c1 += p[i].second - 1;
				}
			}
			sort(x.rbegin(),x.rend());
		//	cout<<l<<','<<r<<','<<c101<<','<<c1<<','<<ii<<endl;
			dfs(l,r,x,c1,c101,ii);
		}
		cout<<ans<<endl;
		
	}
	
	return 0;
}