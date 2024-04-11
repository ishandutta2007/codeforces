#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000


int main(){
	
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		map<pair<int,int>,vector<int>> mp;
		for(int j=0;j<n-2;j++){
			vector<int> a(3);
			for(int k=0;k<3;k++)cin>>a[k];
			for(int x=0;x<3;x++){
				for(int y=x+1;y<3;y++){
					int A = a[x];
					int B = a[y];
					A--;B--;
					if(A>B)swap(A,B);
					mp[make_pair(A,B)].push_back(j);
				}
			}
		}
		if(n==3){
			cout<<"1 2 3"<<endl;
			cout<<"1"<<endl;
			continue;
		}

		vector<vector<int>> Eten(n,vector<int>());

		vector<vector<int>> Ehen(n-2,vector<int>());
		
		for(auto a:mp){
			if(a.second.size()==1){
				Eten[a.first.first].push_back(a.first.second);
				Eten[a.first.second].push_back(a.first.first);
			}
			else{
				Ehen[a.second[0]].push_back(a.second[1]);
				Ehen[a.second[1]].push_back(a.second[0]);
			}
		}
		
		vector<int> p,q;
		int now = 0;
		set<int> visited;
		while(p.size()!=n){
			p.push_back(now);
			visited.insert(now);
			for(int j=0;j<Eten[now].size();j++){
				int to = Eten[now][j];
				if(visited.count(to))continue;
				now = to;
				break;
			}
		}
		
		vector<int> D(n-2,0);
		
		queue<int> Q;
		for(int j=0;j<n-2;j++){
			D[j] = Ehen[j].size();
			if(Ehen[j].size()==1){
				Q.push(j);
			}
		}
		
		set<int> v;
		while(q.size()!=n-2){
			now = Q.front();
			Q.pop();
			if(v.count(now))continue;
			q.push_back(now);
			v.insert(now);
			for(int j=0;j<Ehen[now].size();j++){
				int to = Ehen[now][j];
				if(v.count(to))continue;
				D[to] --;
				if(D[to]==1){
					Q.push(to);
				}
			}
		}
		
		for(int j=0;j<n;j++){
			if(j!=0)cout<<' ';
			cout<<p[j]+1;
		}
		cout<<endl;
		for(int j=0;j<n-2;j++){
			if(j!=0)cout<<' ';
			cout<<q[j]+1;
		}
		cout<<endl;
		
		
		
	}
	
    return 0;
}