#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
	long long  a,b,c,x,y;
	cin >> a;
	if(a==1||a==2)cout <<"-1"<<endl;
	else{
		if(a%2==0){
			b = (a*a-4)/4;
			c = (a*a+4)/4;
			cout << b << " "<< c <<endl;
		}else{
			x = (a+1)/2;
			y = (a-1)/2;
			cout << 2*x*y << " "<< x*x+y*y << endl;
		}	
	}
	return 0;
}