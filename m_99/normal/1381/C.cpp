#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000002


int main(){
	
	int t;
	cin>>t;
	
	for(int _=0;_<t;_++){
		
		int n,x,y;
		scanf("%d %d %d",&n,&x,&y);
		vector<vector<int>> balls(n+1,vector<int>());
		vector<int> a(n);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			a[i]--;
			balls[a[i]].push_back(i);
		}
		priority_queue<pair<int,int>> Q;
		int unused;
		for(int i=0;i<=n;i++){
			if(balls[i].size()==0){
				unused = i;
			}
			else{
				Q.emplace(balls[i].size(),i);
			}
		}
		
		vector<int> ans(n,-1);
		bool f = true;
		for(int i=0;i<x;i++){
			pair<int,int> p = Q.top();
			Q.pop();
			ans[balls[p.second].back()] = p.second;
			balls[p.second].pop_back();
			p.first--;
			if(p.first>0){
				Q.push(p);
			}
		}
		
		y-=x;
		while(y!=0){
			if(y%2==1&&x+y==n){
				if(Q.size()<3){
					f=false;
					break;
				}
				if(y==1){
					f=false;
					break;
				}
				int I[3];
				for(int i=0;i<3;i++){
					I[i] = Q.top().second;
					Q.pop();
				}
				for(int i=0;i<3;i++){
					int X = i;
					int Y = (i+1)%3;
					ans[balls[I[X]].back()] = I[Y];
					balls[I[X]].pop_back();
				}
				for(int i=0;i<3;i++){
					if(balls[I[i]].size()>0){
						Q.emplace(balls[I[i]].size(),I[i]);
					}
				}
				y-=3;
				
			}
			else{
				if(y%2==1){
					if(Q.size()<2){
						f=false;
						break;
					}
					pair<int,int> p,q;
					p = Q.top();
					Q.pop();
					q = Q.top();
					Q.pop();
					ans[balls[p.second].back()] = q.second;
					ans[balls[q.second].back()] = unused;
					balls[p.second].pop_back();
					balls[q.second].pop_back();
					p.first--,q.first--;
					if(p.first>0)Q.push(p);
					if(q.first>0)Q.push(q);
					y--;
				}
				else{
					if(Q.size()<2){
						f=false;
						break;
					}
					pair<int,int> p,q;
					p = Q.top();
					Q.pop();
					q = Q.top();
					Q.pop();
					ans[balls[p.second].back()] = q.second;
					ans[balls[q.second].back()] = p.second;
					balls[p.second].pop_back();
					balls[q.second].pop_back();
					p.first--,q.first--;
					if(p.first>0)Q.push(p);
					if(q.first>0)Q.push(q);
					y-=2;
				}
					
			}
		}
		
		for(int i=0;i<ans.size();i++){
			if(ans[i]==-1)ans[i] = unused;
		}
		if(!f){
			cout<<"NO"<<endl;
		}
		else{
			cout<<"YES"<<endl;
			for(int i=0;i<ans.size();i++){
				if(i!=0)cout<<' ';
				cout<<ans[i]+1;
			}
			cout<<endl;
		}
		
	}
	
	return 0;
}