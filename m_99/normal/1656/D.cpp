#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001



int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		long long n;
		cin>>n;
		n *= 2;
		__int128 tt = n;
		__int128 x=1,y=1;
		while(n%2==0){
			x*=2;
			n/=2;
		}
		y = n;
		if(x>=2 && x * (x+1) <= tt){
			cout<<(long long)x<<endl;
			continue;
		}
		if(y>=2 && y * (y+1) <= tt){
			cout<<(long long)y<<endl;
			continue;
		}
		cout<<-1<<endl;
		
		
	}
	
	return 0;
}