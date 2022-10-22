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
		string s[2];
		rep(i,2)cin>>s[i];
		
		int y = 0,x = 0,py = 0,px = -1;
		while(true){
			if(y<0||y>=2||x<0||x>=n)break;
			if(s[y][x]<='2'){
				int ty = y,tx = x;
				y += (y-py);
				x += (x-px);
				py = ty;
				px = tx;
			}
			else{
				int ty = y,tx = x;
				if(x>px){
					y ^= 1;
				}
				else{
					x++;
				}
				py = ty;
				px = tx;
			}
		}
		if(y==1&&x==n){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
		
	}
	
	return 0;
}