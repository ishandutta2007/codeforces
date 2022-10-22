#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001
#define InfL 4000000000000000001

int main() {
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		vector<int> a(n);
		rep(i,n)scanf("%d",&a[i]);
		
		int ans = 0;
		set<int> sufs;
		int cur =0;
		sufs.insert(0);
		rep(i,n){
			if(sufs.count(a[i]^cur)){
				sufs.clear();
				sufs.insert(0);
				cur = 0;
			}
			else{
				ans++;
				cur ^= a[i];
				sufs.insert(cur);
			}
		}
		
		cout<<ans<<endl;
	}
	
    return 0;
}