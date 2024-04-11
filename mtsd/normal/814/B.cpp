#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int>a(n),b(n),v(n),flag(n+1,0);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	for(int i=0;i<n;i++){
		cin >> b[i];
	}
	vector<int> num;
	for(int i=0;i<n;i++){
		if(a[i]==b[i]&&flag[a[i]]==0){
			v[i]=a[i];
			flag[a[i]]=1;
		}else{
			num.push_back(i);
		}
	}
	vector<int> res;
	for(int i=1;i<=n;i++){
		if(flag[i]==0){
			res.push_back(i);
		}
	}
	if(res.size()==1){
		v[num[0]]=res[0];
	}else{
		int count_a=0,count_b=0;
		if(a[num[0]]==res[0])count_a+=1;	
		if(a[num[1]]==res[1])count_a+=1;
		if(b[num[0]]==res[0])count_b+=1;	
		if(b[num[1]]==res[1])count_b+=1;
		if(count_a==1&&count_b==1){
			v[num[0]]=res[0];
			v[num[1]]=res[1];
		}else{
			v[num[0]]=res[1];
			v[num[1]]=res[0];
		}
	}
	for(int i=0;i<n-1;i++){
		cout << v[i] << " ";
	}
	cout << v[n-1] << endl;
	return 0;
}