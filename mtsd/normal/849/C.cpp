#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>

#define inf  1000000007
#define ll long long
#define PA pair<int,int>
#define PPAP pair<int,pa>
#define  MP make_pair
#define  PB push_back

using namespace std;

int main(){
	int a[10000]={};
	for(int i=1;i<10000;i++){
		a[i] = (i-1)*i/2;
	}
	int k;
	cin >> k;
	int x=0;
	string s;
	if(k==0){
		cout << "a" << endl;
		return 0;
	}
	while(k!=0){
		for(int i=1;i<10000;i++){
			if(a[i]<=k&&a[i+1]>k){
				for(int j=0;j<i;j++){
					s+= ('a'+x);
				}
				k-=a[i];
				x+=1;
				break;
			}
		}
	}
	cout << s << endl;
	return 0;
}