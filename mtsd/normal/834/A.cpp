#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;

int main(){
	char s,t;
	cin >> s >> t;
	int n,a,b;
	cin >> n;
	if(s=='^')a=0;
	if(s=='>')a=1;
	if(s=='v')a=2;
	if(s=='<')a=3;
	if(t=='^')b=0;
	if(t=='>')b=1;
	if(t=='v')b=2;
	if(t=='<')b=3;
	n = n%4;
	if(a==b||(a-b+4)%2==0){
		cout << "undefined" << endl;
	}else{
		if((b-a+4)%4==n){
			cout << "cw" << endl;
		}else{
			cout << "ccw" << endl;
		}
	}
	return 0;
}