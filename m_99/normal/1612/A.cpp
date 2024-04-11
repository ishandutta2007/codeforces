#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		int x,y;
		cin>>x>>y;
		int a = -1,b = -1;
		rep(i,101){
			rep(j,101){
				int X = x+y;
				int Y = i+j;
				int Z = abs(i-x) + abs(j-y);
				if(X==Y*2 && X==Z*2)a = i,b = j;
			}
		}
		cout<<a<<' '<<b<<endl;
	}
	
	return 0;
}