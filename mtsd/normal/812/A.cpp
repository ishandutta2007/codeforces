#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>

using namespace std;

int main(){
	bool a[4][4];
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			cin >> a[i][j]; 
		}
	}
	bool flag[4]={},flag2[4]={};
	for(int i=0;i<4;i++){
		if(a[i][3]==1){
			flag[i]=1;
		}
	}
	for(int i=0;i<4;i++){
		if(a[i][0]==1){
			flag2[i]=1;
			flag2[(i+3)%4]=1;
		}
	}
	for(int i=0;i<4;i++){
		if(a[i][1]==1){
			flag2[i]=1;
			flag2[(i+2)%4]=1;
		}
	}
	for(int i=0;i<4;i++){
		if(a[i][2]==1){
			flag2[i]=1;
			flag2[(i+1)%4]=1;
		}
	}
	for(int i=0;i<4;i++){
		if(flag[i]==1&&flag2[i]==1){
			cout << "YES" <<endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}