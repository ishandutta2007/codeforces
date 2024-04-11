#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000


int main(){
	
	int _t;
	cin>>_t;
	
	
	rep(_,_t){
		
		int n;
		scanf("%d",&n);
		
		deque<int> b(n);
		rep(i,n)scanf("%d",&b[i]);
		
		vector<int> ans;
		rep(i,n){
			if(i%2==0){
				ans.push_back(b.front());
				b.pop_front();
			}
			else{
				ans.push_back(b.back());
				b.pop_back();
			}
		}
		
		rep(i,n){
			if(i!=0)printf(" ");
			printf("%d",ans[i]);
		}
		printf("\n");
		
		
	}
	
	
    return 0;
}