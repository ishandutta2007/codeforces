#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		scanf("%d",&n);
		vector<int> b(n),p(n);
		rep(i,n){
			scanf("%d",&b[i]);
			b[i]--;
		}
		rep(i,n){
			scanf("%d",&p[i]);
			p[i]--;
		}
		if(b[p[0]]!=p[0]){
			printf("-1\n");
			continue;
		}
		//cout<<'a'<<endl;
		vector<int> ans(n,0);
		vector<int> dis(n,-1);
		dis[p[0]] = 0;
		int nxt = 1;
		bool f = true;
		for(int i=1;i<n;i++){
			int D = dis[b[p[i]]];
			if(D==-1){
				f = false;
				break;
			}
			ans[p[i]] = nxt - D;
			dis[p[i]] = nxt;
			nxt++;
		}
		if(!f)printf("-1\n");
		else{
			rep(i,n){
				if(i!=0)printf(" ");
				printf("%d",ans[i]);
			}
			printf("\n");
		}
		
	}
		
	return 0;
}