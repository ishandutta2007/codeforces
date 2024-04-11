#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000000000000

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n,k;
		scanf("%d %d",&n,&k);
		
		vector<long long> a(k),t(n,-1);
		rep(i,k){
			scanf("%lld",&a[i]);
			a[i]--;
		}
		rep(i,k){
			long long temp;
			scanf("%lld",&temp);
			t[a[i]] = temp;
		}			
		
		multiset<long long> A,B;
		rep(i,n){
			if(t[i]==-1)continue;
			B.insert(t[i] + i);
		}
		
		vector<long long> ans(n,Inf);
		
		rep(i,n){
			
			long long temp;
			if(B.size()>0){
				temp = *(B.begin());
				ans[i] = min(ans[i],temp-i);
			}
			if(A.size()>0){
				temp = *(A.begin());
				ans[i] = min(ans[i],temp+i);
			}
			if(t[i]!=-1){
				temp = t[i]+i;
				auto it=  B.lower_bound(temp);
				B.erase(it);
				A.insert(t[i]-i);
			}
		}
		
		rep(i,n){
			if(i!=0)printf(" ");
			printf("%lld",ans[i]);
		}
		printf("\n");
	}
	
	return 0;
}