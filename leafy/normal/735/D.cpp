#include<bits/stdc++.h>
using namespace std;
int n;
inline bool is_prime(int x){
	for(int i=2;i<=sqrt(x+0.5);i++)
		if(x%i==0) return 0;
	return 1;
}

int main(){
	cin>>n;
	if(is_prime(n)){puts("1");return 0;}
	if(n%2==0){puts("2");return 0;}
	if(is_prime(n-2)) puts("2");
	else puts("3");
	return 0;
}