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
		string s;
		cin>>s;
		
		string ans0(n,'.'),ans1(n,'.');
		int c = 0;
		rep(i,s.size()){
			if(s[i]=='0'){
				if(c==0){
					ans0[i] = '(';
					ans1[i] = ')';
					c^=1;
				}
				else{
					ans0[i] = ')';
					ans1[i] = '(';
					c^=1;
				}
			}
		}
		
		if(c){
			printf("NO\n");
			continue;
		}
		
		int remain = n/2;
		rep(i,n){
			if(ans0[i]=='(')remain--;
		}
		
		rep(i,n){
			if(ans0[i]=='.'){
				if(remain>0){
					remain--;
					ans0[i] = '(';
					ans1[i] = '(';
				}
				else{
					ans0[i] = ')';
					ans1[i] = ')';
				}
			}			
		}
		
		c = 0;
		bool f = true;
		rep(i,n){
			if(ans0[i]=='('){
				c++;
			}
			else{
				c--;
			}
			if(c<0){
				f=false;
				break;
			}
		}
		if(c!=0)f=false;
		c = 0;
		rep(i,n){
			if(ans1[i]=='('){
				c++;
			}
			else{
				c--;
			}
			if(c<0){
				f=false;
				break;
			}
		}
		if(c!=0)f=false;
		
		if(f){
			printf("YES\n");
			cout<<ans0<<'\n';
			cout<<ans1<<'\n';
		}
		else{
			printf("NO\n");
		}
	}	
	
    return 0;
}