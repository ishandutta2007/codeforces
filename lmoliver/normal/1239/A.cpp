#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MOD=1e9+7;

int fib(int n){
	int b=1;
	int c=1;
	while(n--){
		c=(c+b)%MOD;
		swap(b,c);
	}
	return c;
}

int main(){
	int n,m;
	cin>>n>>m;
	int a=fib(n);
	int b=fib(m);
	cout<<(a+b-1)%MOD*2%MOD<<endl;
	return 0;
}