#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;

int main(){
	int n,k;
	cin >> n >> k;
	string s;
	cin >> s;
	vector<int>a(n+1);
	for(int i=0;i<26;i++){
		int mi = -1;
		int ma = -1;
		bool flag = 0;
		char target = 'A'+i;
		for(int j=0;j<n;j++){
			if(s[j]==target&&flag==0){
				flag = 1;
				mi = j;
				ma = j;
			}else if(s[j]==target){
				ma = j;
			}
		}
		if(flag){
			a[mi]+=1;
			a[ma+1]-=1;
		}
	}
	for(int i=1;i<n;i++){
		a[i] += a[i-1];
	}
	for(int i=0;i<n;i++){
		if(a[i]>k){
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}