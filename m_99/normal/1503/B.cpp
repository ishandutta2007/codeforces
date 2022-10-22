#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001


int main(){
	
	int n;
	cin>>n;
	
	vector<vector<int>> ans(n,vector<int>(n,0));
	vector<pair<int,int>> P1,P2;
	rep(i,n){
		rep(j,n){
			if((i+j)%2==0)P1.emplace_back(i+1,j+1);
			else P2.emplace_back(i+1,j+1);
		}
	}
	rep(_,n*n){
		
		int ng;
		cin>>ng;
		
		if(ng!=1){
			if(P1.size()>0){
				cout<<1<<' '<<P1.back().first<<' '<<P1.back().second<<endl;
				P1.pop_back();
				continue;
			}
		}
		else if(ng!=2){
			if(P2.size()>0){
				cout<<2<<' '<<P2.back().first<<' '<<P2.back().second<<endl;
				P2.pop_back();
				continue;
			}
		}
		if(P1.size()>0){
			int c;
			if(ng==3)c = 1;
			else c = 3;
			cout<<c<<' '<<P1.back().first<<' '<<P1.back().second<<endl;
			P1.pop_back();
			continue;
		}
		else{
			int c;
			if(ng==3)c = 2;
			else c = 3;
			cout<<c<<' '<<P2.back().first<<' '<<P2.back().second<<endl;
			P2.pop_back();
			continue;
		}
		
	}
			
		
		
	
    return 0;
}