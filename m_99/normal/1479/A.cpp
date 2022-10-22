#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001
int n;
int Q(int t){
	cout<<"? "<<t<<endl;
	int ret;
	cin>>ret;
	return ret;
}

void check(int t){
	if(t<=0)return;
	int x = Q(t);
	int m = Inf;
	if(t!=1){
		m = min(m,Q(t-1));
	}
	if(t!=n){
		m = min(m,Q(t+1));
	}
	if(m > x){
		cout<<"! "<<t<<endl;
		exit(0);
	}
}

int main(){
	
	
	cin>>n;
	double x = 2.618;
	int l = 1,r = n;
	int m0 = 1 + (n-1) / x;
	int m1 = n - (n-1)/x;
	int a = Q(m0),b = Q(m1);
	while(r-l>=3){
		if(m0==m1)break;
		
		if(a>b){
			l = m0;
			m0 = m1;
			a = b;
			m1 = r - (r-l+1)/x;
			b = Q(m1);
		}
		else{
			r = m1;
			m1 = m0;
			b = a;
			m0 = l + (r-l+1)/x;
			a = Q(m0);
		}
	}
	
	for(int i=l-1;i<=r+1;i++){
		check(i);
	}
	
	return 0;
}