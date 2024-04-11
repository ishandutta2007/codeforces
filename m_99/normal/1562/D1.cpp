#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001



int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		int n,q;
		scanf("%d %d",&n,&q);
		string s;
		cin>>s;
		
		
		vector<int> S(n+1,0);
		rep(i,n){
			int t = 1;
			if(i%2==0)t *= -1;
			if(s[i]=='-')t *= -1;
			S[i+1] = t + S[i];
		}
		
		rep(__,q){
			int l,r;
			scanf("%d %d",&l,&r);
			l--;
			if(S[r]-S[l]==0){
				printf("0\n");
				continue;
			}
			if((r-l)%2==0){
				printf("2\n");
				continue;
			}
			printf("1\n");
		}
			
	}
	
	return 0;
}