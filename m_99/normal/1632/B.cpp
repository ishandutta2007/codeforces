#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		int n;
		cin>>n;
		
		vector<int> p;
		int m = 0;
		rep(i,30){
			if(n-1 >= (1<<i))m = 1<<i;
		}
		//cout<<m<<endl;
		for(int i=n-1;i>=m;i--)p.push_back(i);
		rep(i,m)p.push_back(i);
		
		rep(i,n){
			if(i!=0)printf(" ");
			printf("%d",p[i]);
		}
		printf("\n");
		
	}
	
	return 0;
}