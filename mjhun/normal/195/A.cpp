#include <iostream>
int main(){
	int a,b,c,t;
	std::cin>>a>>b>>c;
	t=((a-b)*c)%b;
	std::cout<<((a-b)*c)/b+(t!=0);
	return 0;
}