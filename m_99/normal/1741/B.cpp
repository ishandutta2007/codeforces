#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf32 1000000001
#define Inf64 2000000000000000001



int main(){
	
	int _t;
	cin>>_t;
	rep(_,_t){
		
		int n;
		cin>>n;
		
		if(n==3)cout<<-1<<endl;
		else{
			vector<int> t(n);
			rep(i,n)t[i] = i+1;
			if(n%2==0){
				reverse(t.begin(),t.end());
			}
			else{
				rep(i,3){
					t.push_back(t[0]);
					t.erase(t.begin());
				}
			}
			rep(i,n){
				if(i!=0)cout<<' ';
				cout<<t[i];
			}
			cout<<endl;
		}
	}
	
	return 0;
}