#include <bits/stdc++.h>
using namespace std;

int main() {
	int T; cin>>T;
	while(T--) {
		int n; 
		cin>>n;
		bool last = (n%2 == 1);
		n = (n/2)*2;
		if(n != 0) {
		for(int i=0;i<n/2-1;i++)
			cout<<'a';
		cout<<'b';
		for(int i=0;i<n/2;i++)
			cout<<'a';
		}
		if(last)
			cout<<'c';
		cout<<endl;
	}
	return 0;
}