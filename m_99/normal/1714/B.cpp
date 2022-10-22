#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001



int main() {
   
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		vector<int> a(n);
		rep(i,n)scanf("%d",&a[i]);
		set<int> s;
		int ans = 0;
		for(int i=n-1;i>=0;i--){
			if(s.count(a[i])){
				ans = i+1;
				break;
			}
			s.insert(a[i]);
		}
		cout<<ans<<endl;
		
	}
	
    return 0;
}