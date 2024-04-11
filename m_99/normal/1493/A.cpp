#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001



int main(){
	
	int T;
	cin>>T;
	
	rep(_,T){
		int n,k;
		scanf("%d %d",&n,&k);
		
		vector<int> a;
		for(int i=k-1;i>=1;i--){
			if(a.size()==0)a.push_back(i);
			else{
				if(a.back() + i <= k)break;
				else a.push_back(i);
			}
		}
		for(int i=k+1;i<=n;i++){
			a.push_back(i);
		}
		
		printf("%d\n",a.size());
		rep(i,a.size()){
			if(i!=0)printf(" ");
			printf("%d",a[i]);
		}
		printf("\n");
	}
	
    return 0;
}