#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001


int main(){
	
	int n;
	cin>>n;
	
	vector<int> a(n);
	rep(i,n){
		scanf("%d",&a[i]);
	}
	
	map<int,vector<array<int,3>>> mp;
	array<int,3> temp;
	rep(i,n){
		int last = Inf + i;
		set<int> S;
		rep(j,1000){
			if(S.count(a[i]))break;

			S.insert(a[i]);
			temp = {j,i,last};
			mp[a[i]].push_back(temp);
			last = a[i];
			
			rep(k,100){
				if((1<<k)>=a[i]){
					a[i] = (1<<k)-a[i];
					break;
				}
			}
		}
	}
	
	int maxi = -1,x,y;
	
	for(auto a:mp){
		auto v = a.second;
		vector<array<int,3>> cur;
		rep(i,v.size()){
			rep(j,cur.size()){
				if(cur[j][2]==v[i][2])continue;
				if(maxi < cur[j][0] + v[i][0]){
					maxi = cur[j][0]+v[i][0];
					x = cur[j][1];
					y = v[i][1];
				}
			}
			cur.push_back(v[i]);
			sort(cur.rbegin(),cur.rend());
			if(cur.size()>=3){
				if(cur[0][2]==cur[1][2])cur.erase(cur.begin()+1);
				else cur.pop_back();
			}
			
		}
	}
	
	cout<<x+1<<' '<<y+1<<' '<<maxi<<endl;
	
	return 0;
}