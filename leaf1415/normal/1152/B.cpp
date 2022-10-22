#include <iostream>
#include <vector>

using namespace std;

int x;
vector<int> ans;

bool check(int x)
{
	return !(x & (x+1));
}

int main(void)
{
	cin >> x;
	
	int t = 0;
	for(int i = 0; i < 40; i++){
		if(check(x)) break;
		for(int j = 19; j >= 0; j--){
			if((x&(1<<j)) == 0){
				x ^= (1<<(j+1)) - 1;
				ans.push_back(j+1);
				break;
			}
		}
		t++;
		if(check(x)) break;
		x++, t++;
		if(check(x)) break;
	}
	if(t == 0){
		cout << 1 << endl;
		cout << 0 << endl;
		return 0;
	}
	
	cout << t << endl;
	for(int i = 0; i < ans.size(); i++) cout<< ans[i] << " "; cout << endl;
	
	return 0;
}