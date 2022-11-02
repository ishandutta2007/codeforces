#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int k,r;
	cin>>k>>r;
	for (int i=1;;i++){
		int p=i*k;
		if (p%10==0||p%10==r){
			cout<<i<<endl;
			return 0;
		}
	}
}