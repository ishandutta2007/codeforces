#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> ans1, ans2;

int main(void)
{
	cin >> n;
	if(n <= 2){
		cout << "No" << endl;
		return 0;
	}
	
	if(n % 2 == 0){
		ans1.push_back(1), ans1.push_back(n);
		for(int i = 2; i < n; i++) ans2.push_back(i);
	}
	else{
		ans1.push_back(n);
		for(int i = 1; i < n; i++) ans2.push_back(i);
	}
	
	cout << "Yes" << endl;
	cout << ans1.size() << " ";
	for(int i = 0; i < ans1.size(); i++) cout << ans1[i] << " "; cout << endl;
	cout << ans2.size() << " ";
	for(int i = 0; i < ans2.size(); i++) cout << ans2[i] << " "; cout << endl;
	
	return 0;
}