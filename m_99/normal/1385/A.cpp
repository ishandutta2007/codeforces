#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		int x,y,z;
		cin>>x>>y>>z;
		vector<int> as = {x,y,1},bs = {x,z,1},cs = {y,z,1};
		bool f = false;
		rep(i,3){
			rep(j,3){
				rep(k,3){
					int a = as[i],b = bs[j],c = cs[k];
					
					if(x==max(a,b)&&y==max(c,a)&&z==max(b,c)){
						f = true;
						cout<<"YES"<<endl;
						cout<<a<<' '<<b<<' '<<c<<endl;
						goto L;
					}
				}
			}
		}
		L:;
		if(!f)cout<<"NO"<<endl;
		
		
	}
	
	return 0;
}