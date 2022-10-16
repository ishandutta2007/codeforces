#include<bits/stdc++.h>
using namespace std;
int n;
multiset<int>v;
multiset<int>used;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		v.insert(x);
	}
	auto x=v.end();
	x--;
	int a=*x;
	for(multiset<int>::iterator T=v.begin();T!=v.end();){
		if(a%*T==0&&used.count(*T)==0)used.insert(*T),v.erase(T++);
		else T++;
	}
	x=v.end();x--;
	cout<<*x<<" "<<a<<endl;
	return 0;
}