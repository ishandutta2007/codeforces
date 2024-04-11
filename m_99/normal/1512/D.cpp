#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

bool check(vector<long long> b,long long S){
	long long sum = 0LL;
	rep(i,b.size()){
		sum += b[i];
	}
	int d = distance(b.begin(),lower_bound(b.begin(),b.end(),sum-S));
	
	if(d!=b.size() && b[d]==sum-S){
		b.erase(b.begin()+d);
		rep(i,b.size()){
			if(i!=0)printf(" ");
			printf("%lld",b[i]);
		}
		printf("\n");
		return true;
	}
	return false;
}

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		
		vector<long long> b(n+2);
		rep(i,n+2){
			scanf("%lld",&b[i]);
		}
		sort(b.begin(),b.end());
		long long S = b.back();
		b.pop_back();
		
		if(check(b,S))continue;
		
		swap(b.back(),S);
		if(check(b,S))continue;
		
		cout<<-1<<endl;
		
	}
	
	return 0;
}