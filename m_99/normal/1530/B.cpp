#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001


int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int h,w;
		cin>>h>>w;
		
		vector<string> s(h,string(w,'0'));
		
		vector<int> y,x;
		rep(i,w){
			y.push_back(0);
			x.push_back(i);
		}
		rep(i,h-1){
			y.push_back(i+1);
			x.push_back(w-1);
		}
		rep(i,w-1){
			y.push_back(h-1);
			x.push_back(w-2-i);
		}
		rep(i,h-2){
			y.push_back(h-2-i);
			x.push_back(0);
		}
		
		vector<int> dx = {1,0,-1},dy = {1,0,-1};
		
		rep(i,y.size()){
			int yy = y[i],xx = x[i];
			bool f = true;
			rep(j,3){
				rep(k,3){
					int yyy = yy + dx[j],xxx = xx+dy[k];
					if(yyy<0||yyy>=h||xxx<0||xxx>=w)continue;
					if(s[yyy][xxx]=='1'){
						f=false;
					}
				}
			}
			if(f)s[yy][xx] = '1';
		}
		
		rep(i,h)cout<<s[i]<<endl;
		
	}	
	
	return 0;
}