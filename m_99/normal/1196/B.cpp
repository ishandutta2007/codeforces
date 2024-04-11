#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001


int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n,k;
		scanf("%d %d",&n,&k);
		vector<int> a(n);
		rep(i,n){
			scanf("%d",&a[i]);
			a[i] &= 1;
		}
		
		int last = -1;
		vector<int> ans;
		int sum = 0;
		rep(i,n){
			if(a[i]){
				ans.push_back(i+1);
			}
		}
		if(ans.size()<k){
			cout<<"NO"<<endl;
			continue;
		}
		if((ans.size()-k)%2==1){
			cout<<"NO"<<endl;
			continue;
		}
		
		while(ans.size()!=k){
			rep(i,2)ans.pop_back();
		}
		ans.back() = n;
		
		cout<<"YES"<<endl;
		rep(i,ans.size()){
			if(i!=0)printf(" ");
			printf("%d",ans[i]);
			
		}
		cout<<endl;
		
		
		
	}
	
	return 0;
}