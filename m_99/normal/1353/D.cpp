#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		
		priority_queue<pair<int,int>> Q;
		Q.emplace(n,-1);
		
		vector<int> ans(n,-1);
		
		rep(i,n){
			pair<int,int> p = Q.top();
			Q.pop();
			int l = -p.second;
			int r = l+p.first-1;
			//l++;
			//r++;
			//cout<<l<<','<<r<<endl;
			int m;
			if(p.first%2==1){
				m = (l+r+1)/2;
			}
			else{
				m = (l+r)/2;
			}
			m--;
			ans[m] = i;
			m++;
			if(m-l!=0){
				Q.emplace(m-l,-l);
			}
			if(r-m!=0){
				Q.emplace(r-m,-(m+1));
			}
		}
		
		rep(i,n){
			if(i!=0)printf(" ");
			printf("%d",ans[i]+1);
		}
		cout<<endl;
		
	}
	
	return 0;
}