#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001
int l,r;

int get(int b){
	return min(b-1,r-b);
}

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		
		cin>>l>>r;
		int x = l,y = r;
		while(y-x>3){
			int m0 = x + (y-x)/3;
			int m1 = m0 + (y-x)/3;
			if(get(m0)>=get(m1))y = m1;
			else x = m0;
		}
		
		int ans = 0;
		for(int i=x;i<=y;i++)ans = max(ans,get(i));
		
		cout<<ans<<endl;
		
	}
	
	return 0;
}