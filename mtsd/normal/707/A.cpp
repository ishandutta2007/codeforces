#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
	int n,m,x,flag;
	char s;
	flag =0;
	cin >>n>>m;
	x = n*m;
	for(int i=0;i<x;i++){
		cin >> s;
		if(s!='B'&&s!='W'&&s!='G'){
			flag =1;
		}
	}
	if(flag==0){
		cout << "#Black&White"<<endl;
	}else{
		cout << "#Color"<<endl;
	}
	return 0;
}