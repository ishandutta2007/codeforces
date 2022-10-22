#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int main(){	
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n,m;
		cin>>n>>m;
		
		string s;
		cin>>s;
		
		int cx = 0,cy = 0;
		int mx = 0,Mx = 0,my = 0,My = 0;
		int ansx=1,ansy=1;
		rep(i,s.size()){
			if(s[i]=='L')cy--;
			if(s[i]=='R')cy++;
			if(s[i]=='D')cx++;
			if(s[i]=='U')cx--;
			mx = min(mx,cx);
			Mx = max(Mx,cx);
			my = min(my,cy);
			My = max(My,cy);
			if(Mx-mx+1>n)break;
			if(My-my+1>m)break;
			ansx = 1 - mx;
			ansy = 1-my;
		}
		printf("%d %d\n",ansx,ansy);
	}
	
	return 0;
	
}