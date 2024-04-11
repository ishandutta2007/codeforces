#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001


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
		
		bool f = true;
		long long l = 1LL;
		/*
		for(int i=2;i<=30;i++){
			l = lcm(l,i);
		}
		cout<<l<<endl;
		*/
		rep(i,min(n,30)){
			l = lcm(i+2,l);
			//cout<<l<<endl;
			if(a[i]%l==0){
				f=  false;
				break;
			}
		}
		
		if(!f)printf("NO\n");
		else printf("YES\n");
		
	}
	
	return 0;
	
}