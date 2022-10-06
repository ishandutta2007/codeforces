#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;

int main(){
	string s;
	cin >> s;
	int x,y;
	x = (s[0]-'0')*10+(s[1]-'0');
	y = (s[3]-'0')*10+(s[4]-'0');
	if(x<=5){
		if(y<=x*10){
			cout << x*10-y << endl;
		}else{
			if(x!=5){
				cout << 60+(x+1)*10-y << endl;
			}else{
				cout << 241+60-y << endl;
			}
		}
	}else if(x<=9){
		cout << 61-y+60*(10-x-1) << endl;
	}else if(x<=15){
		if(y<=10*(x%10)+x/10){
			cout << 10*(x%10)+x/10-y << endl;
		}else{
			if(x!=15){
				cout << 60-y + 10*(x%10+1)+x/10 << endl;
			}else{
				cout << 242+60-y << endl;
			}
		}
	}else if(x<=19){
		cout << 62-y+60*(20-x-1) << endl;
	}else{
		if(y<=10*(x%10)+x/10){
			cout << 10*(x%10)+x/10-y << endl;
		}else{
			if(x!=23){
				cout << 62-y + 10*(x%10+1) << endl;
			}else{
				cout << 60-y << endl;
			}
		}
	}
	return 0;
}