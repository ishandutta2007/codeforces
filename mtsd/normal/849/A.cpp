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
	int n;
	cin >> n;
	vector<int>v(n);
	for(int i=0;i<n;i++){
		cin >> v[i];
	}
	if(v[0]%2==0||v[n-1]%2==0||n%2==0){
		cout << "No" << endl;
	}else{
		cout << "Yes" << endl;
	}

	return 0;
}