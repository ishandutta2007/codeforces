#include <iostream>
#include <vector>
#define llint long long

using namespace std;

llint n;
llint p[200005], pinv[200005];
bool used[200005];
vector<llint> vec, vec2;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> p[i];
	for(int i = 1; i <= n; i++) pinv[p[i]] = i;
	
	for(int i = 1; i <= n; i++){
		if(pinv[i] == 0){
			if(p[i] == 0) vec.push_back(i);
			else vec2.push_back(i);
		}
	}
	
	if(vec.size() == 1){
		p[vec.front()] = vec2.back();
		vec2.pop_back();
		vec2.push_back(vec.front());
		vec.pop_back();
	}
	
	if(vec.size() >= 2){
		for(int i = 0; i < vec.size(); i++){
			p[vec[i]] = vec[(i+1)%(int)vec.size()];
		}
	}
	
	for(int i = 1; i <= n; i++){
		if(p[i] == 0){
			p[i] = vec2.back();
			vec2.pop_back();
		}
	}
	
	for(int i = 1; i <= n; i++) cout << p[i] << " "; cout << endl;
	
	return 0;
}