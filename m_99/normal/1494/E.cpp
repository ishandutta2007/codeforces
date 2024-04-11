#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1200000000
	

int main(){
	
	int n,m;
	scanf("%d %d",&n,&m);
	
	map<pair<int,int>,char> X,Y;
	
	int cnt = 0;
	int cnt2 = 0;
	rep(i,m){
		char c;
		cin>>c;
		
		if(c=='+'){
			int u,v;
			scanf("%d %d",&u,&v);
			cin>>c;
			u--;v--;
			bool f = false;
			if(u>v){
				swap(u,v);
				swap(X,Y);
				f=true;
			}
			
			X[make_pair(u,v)] = c;
			if(Y.count(make_pair(u,v))&&Y[make_pair(u,v)]==c){
				cnt++;
			}
			if(f){
				swap(X,Y);
			}
			if(X.count(make_pair(u,v))&&Y.count(make_pair(u,v)))cnt2++;
		}
		else if(c=='-'){
			int u,v;
			scanf("%d %d",&u,&v);
			u--;v--;
			bool f = false;
			if(u>v){
				swap(u,v);
				swap(X,Y);
				f=true;
			}
			c = X[make_pair(u,v)];
			X.erase(make_pair(u,v));
			if(Y.count(make_pair(u,v))&&Y[make_pair(u,v)]==c)cnt--;
			if(Y.count(make_pair(u,v)))cnt2--;
			if(f){
				swap(X,Y);
			}
		}
		else{
			int k;
			scanf("%d",&k);

			if(k%2==0){
				if(cnt==0)printf("NO\n");
				else printf("YES\n");
			}
			else{
				if(cnt2==0)printf("NO\n");
				else printf("YES\n");
			}
		}
	}
	
    return 0;
}