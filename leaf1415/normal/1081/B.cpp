#include <iostream>
#include <vector>

using namespace std;

int n;
int a[100005];
vector<int> vec[100005];
int ans[100005];

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) vec[n-a[i]].push_back(i);
	
	int id = 0;
	for(int i = 1; i <= n; i++){
		if((int)vec[i].size() % i){
			cout << "Impossible" << endl;
			return 0;
		}
		for(int j = 0; j < vec[i].size(); j++){
			if(j % i == 0) id++;
			ans[vec[i][j]] = id;
		}
	}
	
	cout << "Possible" << endl;
	for(int i = 1; i <= n; i++) cout << ans[i] << " "; cout << endl;
}