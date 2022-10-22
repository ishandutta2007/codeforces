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
		cin>>n;
		deque<int> a(n);
		rep(i,n)scanf("%d",&a[i]);
		while(a.size()>0&&a.back()==0)a.pop_back();
		while(a.size()>0&&a.front()==0)a.pop_front();
		int ans= 0;
		if(a.size()==0)ans = 0;
		else{
			ans = 1;
			rep(i,a.size()){
				if(a[i]==0){
					ans = 2;
					break;
				}
			}
		}
		cout<<ans<<endl;
		
		
	}
	
    return 0;
}