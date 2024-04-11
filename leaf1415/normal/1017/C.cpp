#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> vec;

int main(void)
{
	cin >> n;
	
	int min_i, min_val = 1e9;
	for(int i = 1; i <= n; i++){
		int j = (n+i-1) / i;
		if(min_val > i+j){
			min_val = i+j;
			min_i = i;
		}
	}
	
	for(int i = 1; i <= (n+min_i-1) / min_i; i++){
		for(int j = min_i*i; j > min_i*(i-1); j--){
			vec.push_back(j);
		}
	}
	
	for(int i = 0; i < vec.size(); i++){
		if(vec[i] <= n) cout << vec[i] << " ";
	}
	cout << endl;
	return 0;
}