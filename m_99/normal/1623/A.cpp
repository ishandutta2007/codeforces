#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n,m,rb,cb,rd,cd;
		cin>>n>>m>>rb>>cb>>rd>>cd;
		int dr = 1,dc = 1;
		rep(i,1000000000){
			if(rb==rd||cb==cd){
				cout<<i<<endl;
				break;
			}
			
			rb += dr;
			if(rb<=0||rb>n){
				rb -= 2*dr;
				dr *= -1;
			}
			cb += dc;
			if(cb<=0||cb>m){
				cb-=2*dc;
				dc*=-1;
			}
		}
			
	}
	
	return 0;
}