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
		vector<int> a(n);
		int m = 0;
		rep(i,n){
			scanf("%d",&a[i]);
			m = max(m,a[i]);
		}
		bool f = true;
		if(n==1){
			if(a[0]!=1)f = false;
		}
		else{
			int c = 0;
			rep(i,n){
				if(a[i]==m||a[i]==m-1)c++;
			}
			if(c<=1)f = false;
		}
		if(f)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		
	}
	
	return 0;
}