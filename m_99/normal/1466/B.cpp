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
		vector<int> a(n);
		
		rep(i,n){
			scanf("%d",&a[i]);
		}
		
		for(int i=n-1;i>=0;i--){
			if(i==n-1||a[i]+1<a[i+1])a[i]++;
		}
		
		a.erase(unique(a.begin(),a.end()),a.end());
		
		cout<<a.size()<<endl;
		
		
		
		
		
	}
	
    return 0;
}