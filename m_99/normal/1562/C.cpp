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
		int ind = -1;
		rep(i,n){
			if(s[i]=='0'){
				ind = i;
				break;
			}
		}
		ind++;
		int l0,r0,l1,r1;
		if(ind==0){
			l0 = 1;
			r0 = n/2;
			l1 = 1;
			r1 = r0*2;
			swap(r0,r1);
		}
		else if(ind>n/2){
			l0 = 1;
			r0 = ind;
			l1 = 1;
			r1 = ind-1;
		}
		else{
			l0 = ind;
			r0 = n;
			l1 = ind+1;
			r1 = n;
		}
		cout<<l0<<' '<<r0<<' '<<l1<<' '<<r1<<endl;
	}
	
	return 0;
}