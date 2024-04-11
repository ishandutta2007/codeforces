#include <bits/stdc++.h>
#define ll long long
ll x;
int main(){
	std::cin>>x;
	for(ll i=2;i*i<=x;++i){
		if (x%i==0){
			while (x%i==0)x/=i;
			if (x>1){printf("1");return 0;}
			std::cout<<i;return 0;
		}
	}if (x)std::cout<<x;
	return 0;
}