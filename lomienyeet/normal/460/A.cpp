#include <bits/stdc++.h>
using namespace std;
int main (){
	int a, b, c;
	cin>>a>>b;
	c=0;
	while(a>0){
		a--;
		c++;
		if(c%b==0)a++;
	}
	cout<<c<<"\n";
	return 0;
}