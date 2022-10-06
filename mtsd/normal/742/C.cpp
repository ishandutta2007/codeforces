#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int gcd(int x,int y){
	int a;
	if(x<y){
		a = x;
		x = y;
		y = a;
	}
	while(1){
		if(y==0)return x;
		a = x;
		x = y;
		y = a%y;
	}
}
int main(){
	int a[101]={};
	int roop[101]={};
	int n;
	int s;
	vector <int> v;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		s = i;
		for(int j=1;j<103;j++){
			if(j==102){
				cout << -1 <<endl;
				return 0;
			}
			if(a[s]==i){
				roop[i]=j;
				break;
			}else{
				s = a[s];
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(roop[i]==1)continue;
		if(v.size()==0){
			v.push_back(roop[i]);
		}else{
			for(int j=0;j<v.size()+1;j++){
				if(j==v.size()){
					v.push_back(roop[i]);
					break;
				}
				if(v[j]==roop[i])break;
			}
		}
	}
	long long ans=1;
	for(int i=0;i<v.size();i++){
		if(v[i]%2==0)v[i]= v[i]/2;
		ans = ans *v[i]/gcd(ans,v[i]);
	}
	cout << ans << endl;
	return 0;
}