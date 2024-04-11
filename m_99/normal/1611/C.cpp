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
		deque<int> a(n);
		rep(i,n){
			scanf("%d",&a[i]);
		}
		deque<int> ans;
		if(a[0]!=n&&a.back()!=n){
			printf("-1\n");
		}
		else{
			while(a.size()!=0){
				if(a.front()>a.back()){
					ans.push_front(a.front());
					a.pop_front();
				}
				else{
					ans.push_back(a.back());
					a.pop_back();
				}
			}
			rep(i,n){
				if(i!=0)printf(" ");
				printf("%d",ans[i]);
			}
			printf("\n");
		}
		
		
	}
		
	return 0;
}