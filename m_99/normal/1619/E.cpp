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
		vector<int> cnt(n+2,0);
		rep(i,n){
			int a;
			scanf("%d",&a);
			cnt[a]++;
		}
		priority_queue<int> Q;
		long long last = 0;
		vector<long long> ans(n+1,0);
		rep(i,n+1){
			if(cnt[i]>0){
				ans[i] = last + cnt[i];
				rep(j,cnt[i]-1)Q.push(i);
			}
			else{
				ans[i] = last;
				if(Q.size()==0){
					for(int j=i+1;j<=n;j++){
						ans[j]  =-1;
					}
					break;
					
				}
				else{
					last += i - Q.top();
					Q.pop();
				}
			}
		}
		rep(i,n+1){
			if(i!=0)printf(" ");
			printf("%lld",ans[i]);
		}
		cout<<endl;
		
	}
	return 0;
}