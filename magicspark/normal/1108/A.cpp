#include<bits/stdc++.h>
int main(){
	int q;
	std::cin>>q;
	while(q--){
		int l,r,forbid;
		std::cin>>l>>r;
		std::cout<<l<<'\n';
		forbid=l;
		std::cin>>l>>r;
		std::cout<<(l==forbid?r:l)<<'\n';
	}
}