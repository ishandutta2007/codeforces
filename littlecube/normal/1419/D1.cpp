#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	int n;
	vector<int> ice;
	cin >> n;
	for(int i = 0; i < n; i++){
		int tmp;
		cin >> tmp;
		ice.push_back(tmp);
	}
	sort(ice.begin(),ice.end());
	cout << (n+1)/2 - 1 << '\n';
	for(int i = 0; i < n/2; i++){
		cout << ice[i+n/2] << " " << ice[i]<< " ";
	}
	if(n%2)cout << ice[n-1];
	cout <<'\n';


	return 0;
}