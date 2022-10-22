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
		int k;
		scanf("%d",&k);
		int cur = 0;
		rep(i,n){
			cout<<(cur^i)<<endl;
			int ret;
			scanf("%d",&ret);
			if(ret==0){
				cur = i;
			}
			else{
				break;
			}
		}
	}
	
    return 0;
}