#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

int isp(int x) {
	for (int y=2;y<x;y++){
		if (x%y==0) return 0;
	}
	return 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int f=0;
	int qq=0;
	for (int i=2;i<=10;i++){
		if (isp(i)) {
			qq++;
			cout<<i<<endl;
			string v;
			cin>>v;
			if (v=="yes"){
				f=i;
				break;
			}
		}
	}
	if (f==0){
		cout<<"prime"<<endl;
		return 0;
	}
	for (int i=2;i*f<=100;i++){
		if (isp(i)&&qq<20) {
			cout<<i*f<<endl;
			string v;
			cin>>v;
			if (v=="yes"){
				cout<<"composite"<<endl;
				return 0;
			}
			qq++;
		}
	}
	cout<<"prime"<<endl;
}