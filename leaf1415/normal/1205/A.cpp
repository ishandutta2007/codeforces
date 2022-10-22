#include <iostream>
#include <vector>
#define llint long long

using namespace std;

llint n;
vector<llint> vec, vec2;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	if(n % 2 == 0){
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	for(int i = 1; i<= n; i++){
		if(i%2) vec.push_back(2*i-1), vec2.push_back(2*i);
		else vec.push_back(2*i), vec2.push_back(2*i-1);
	}
	for(int i = 0; i < vec.size(); i++) cout << vec[i] << " ";
	for(int i = 0; i < vec2.size(); i++) cout << vec2[i] << " ";
	cout << endl;
	
	return 0;
}