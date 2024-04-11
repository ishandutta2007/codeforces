#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001


int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n,m,x;
		scanf("%d %d %d",&n,&m,&x);
		vector<int> h(n);
		rep(i,n){
			scanf("%d",&h[i]);
		}
		vector<int> ans(n);
		
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> Q;
		rep(i,m){
			Q.emplace(0,i+1);
		}
		
		rep(i,n){
			pair<int,int> p = Q.top();
			Q.pop();
			//cout<<p.first<<','<<p.second<<endl;
			ans[i] = p.second;
			p.first += h[i];
			Q.push(p);
		}
		printf("YES\n");
		rep(i,n){
			if(i!=0)printf(" ");
			printf("%d",ans[i]);
		}
		printf("\n");
		
	}
	
    return 0;
}