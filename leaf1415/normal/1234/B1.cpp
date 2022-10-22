#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <algorithm>
#define llint long long

using namespace std;

llint n, k;
set<llint> S;
queue<llint> Q;
vector<llint> vec;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	llint id;
	for(int i = 0; i < n; i++){
		cin >> id;
		if(S.count(id)) continue;
		if(S.size() < k){
			S.insert(id);
			Q.push(id);
		}
		else{
			S.erase(Q.front());
			Q.pop();
			S.insert(id);
			Q.push(id);
		}
	}
	
	while(Q.size()) vec.push_back(Q.front()), Q.pop();
	reverse(vec.begin(), vec.end());
	
	cout << (int)vec.size() << endl;
	for(int i = 0; i < vec.size(); i++) cout << vec[i] << " "; cout << endl;
	
	return 0;
}