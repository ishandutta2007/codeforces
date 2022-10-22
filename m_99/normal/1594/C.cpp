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
		char c;
		string s;
		cin>>c>>s;
		
		if(s==string(n,c)){
			printf("0\n");
			continue;
		}
		bool F = false;
		for(int i=2;i<=n;i++){
			bool f = true;
			for(int j=i;j<=n;j+=i){
				if(s[j-1]!=c)f = false;
			}
			if(f){
				F = true;
				printf("1\n%d\n",i);
				break;
			}
		}
		
		if(!F){
			printf("2\n%d %d\n",n,n-1);
		}
		
	}
	
	return 0;
}