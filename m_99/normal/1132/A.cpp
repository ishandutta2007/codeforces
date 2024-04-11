#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000001

int main(){
	
	long long a,b,c,d;
	cin>>a>>b>>c>>d;
	
	long long cur = a*2;
	if(cur==0&&c>0){
		cout<<0<<endl;
		return 0;
	}
	cur -= d*2;
	if(cur!=0)cout<<0<<endl;
	else cout<<1<<endl;
	
	return 0;
}