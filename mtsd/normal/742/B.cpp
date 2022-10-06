#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
	long long a[1000001]={};
	vector<int> v;
	long long n,x,tmp;
	long long ans=0;
	cin >> n >> x;
	for(int i=0;i<n;i++){
		cin >> tmp;
		v.push_back(tmp);
		a[tmp]+=1;
	}
	if(x==0){
		for(int i=1;i<=100000;i++){
			if(a[i]>1){
				ans += a[i]*(a[i]-1)/2;
			}
		}
	}else{
		for(int i=1;i<=100000;i++){
			if(a[i]!=0){
				ans += a[i]*a[i^x];
			}
		}
		ans = ans/2;
	}
	cout << ans << endl;
	return 0;
}