#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001


int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n,k;
		cin>>n>>k;
		
		vector<int> c(26,0);
		string s;
		cin>>s;
		rep(i,n){
			c[s[i]-'a']++;
		}
		
		int e = 0,o = 0;
		rep(i,26){
			e += c[i] / 2;
			o += c[i] % 2;
		}
		
		int ok = 0,ng = n+1;
		while(ng-ok>1){
			int mid = (ok+ng)/2;
			
			int ee = e,oo = o;
			bool f = true;
			rep(i,k){
				if(mid%2==0){
					ee -= mid/2;
					if(ee<0){
						f = false;
						break;
					}
				}
				else{
					ee -= mid/2;
					if(ee<0){
						f = false;
						break;
					}
					if(oo>0){
						oo--;
					}
					else{
						ee--;
						oo++;
						if(ee<0){
							f = false;
							break;
						}
					}
					
				}
				
			}
			if(f)ok = mid;
			else ng = mid;
		}
		cout<<ok<<endl;
		
	}
	
	return 0;
}