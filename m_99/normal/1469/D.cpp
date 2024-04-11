#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000



int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		scanf("%d",&n);
		
		int M = 16;
		M = min(M,n);
		
		vector<int> x,y;
		
		for(int i=3;i<=n-1;i++){
			if(i==M)continue;
			x.push_back(i);
			y.push_back(i+1);
		}
		
		if(M!=n){
			int t = n;
			while(t!=1){
				x.push_back(n);
				y.push_back(M);
				t = (t+M-1)/M;
			}
		}
		int t = M;
		while(t!=1){
			x.push_back(M);
			y.push_back(2);
			t = (t+1)/2;
		}
		
		cout<<x.size()<<endl;
		rep(i,x.size()){
			printf("%d %d\n",x[i],y[i]);
		}
		
	}
	
    return 0;
}