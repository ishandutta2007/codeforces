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
		
		string s;
		cin>>s;
		int l = -2,r = -2;
		rep(i,n){
			int sum = 0;
			for(int j=i;j<n;j++){
				if(s[j]=='a')sum++;
				else sum--;
				
				if(sum==0){
					l = i,r = j;
				}
			}
		}
		l++;r++;
		cout<<l<<' '<<r<<endl;
	}
	
	return 0;
}