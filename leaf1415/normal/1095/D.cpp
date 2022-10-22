#include <iostream>
#include <utility>
#include <vector>

using namespace std;
typedef pair<int, int> P;

int n;
int ans[200005];
vector<int> vec[200005];

int main(void)
{
	cin >> n;
	int a, b;
	for(int i = 1; i <= n; i++){
		cin >> a >> b;
		vec[i].push_back(a);
		vec[i].push_back(b);
	}
	
	if(n == 3){
		cout << "1 2 3" << endl;
		return 0;
	}
	
	for(int i = 1; i <= n; i++){
		int x = vec[i][0], y = vec[i][1];
		if(vec[x][0] == y || vec[x][1] == y) ans[i] = x;
		else ans[i] = y;
	}
	
	int p = 1;
	do{
		cout << ans[p] << " ";
		p = ans[p];
	}while(p != 1);
	
	return 0;
}