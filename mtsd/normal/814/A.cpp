#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
	int n,k,tmp,count;
	vector<int>a,b;
	cin >> n >> k;
	count = 0;
	for(int i=0;i<n;i++){
		cin >> tmp;
		if(tmp==0)count +=1;
		a.push_back(tmp);
	}
	for(int i=0;i<count;i++){
		cin >> tmp;
		b.push_back(tmp);
	}
	sort(b.begin(),b.end(),greater<int>());
	int x=0;
	for(int i=0;i<n;i++){
		if(a[i]==0){
			a[i]=b[x];
			x+=1;
		}
	}
	for(int i=1;i<n;i++){
		if(a[i]<a[i-1]){
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}