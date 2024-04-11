#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000000000000

long long get(vector<int> a,vector<int> b){
	if(a.size()!=b.size())return Inf;
	long long ret = 0;
	rep(i,a.size())ret += abs(a[i]-b[i]);
	return ret;
}

int main(){
	
	int _t;
	cin>>_t;
	
	
	rep(_,_t){
		
		int n;
		cin>>n;
		
		vector<int> a(n);
		vector<int> t;
		vector<int> x[2];
		rep(i,n){
			scanf("%d",&a[i]);
			if(a[i]%2==1){
				t.push_back(i);
			}
			x[i%2].push_back(i);
		}
		
		long long ans = min(get(t,x[0]),get(t,x[1]));
		if(ans==Inf)ans = -1;
		cout<<ans<<endl;
		
	}
	
	return 0;
}