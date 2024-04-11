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
		
		vector<int> a(n);
		
		rep(i,n)cin>>a[i];
		int ans = 0;
		for(int i=2;i<=100;i++){
			vector<int> b = a;
			int temp = 0;
			while(b.size()!=0){
				int t = b.back();
				b.pop_back();
				rep(j,b.size()){
					if(b[j]+t==i){
						b.erase(b.begin()+j);
						temp++;
						break;
					}
				}
			}
			ans = max(ans,temp);			
		}
		cout<<ans<<endl;
	}
	
	return 0;
}