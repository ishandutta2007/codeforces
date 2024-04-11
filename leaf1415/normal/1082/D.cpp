#include <iostream>
#include <vector>
#include <utility>

using namespace std;
typedef pair<int, int> P;

int n;
int a[505];
vector<P> ans;
vector<int> single, multi;

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	int sum = 0;
	for(int i = 1; i <= n; i++) sum += a[i];
	if(sum < 2*(n-1)){
		cout << "NO" << endl;
		return 0;
	}
	
	for(int i = 1; i <= n; i++){
		if(a[i] == 1) single.push_back(i);
		else multi.push_back(i);
	}
	int dia = (int)multi.size()-1;
	for(int i = 0; i < (int)multi.size()-1; i++){
		ans.push_back(make_pair(multi[i], multi[i+1]));
		a[multi[i]]--, a[multi[i+1]]--;
	}
	
	if(single.size() == 1){
		ans.push_back(make_pair(multi.back(), single[0]));
		dia++;
	}
	else if(single.size() >= 2){
		ans.push_back(make_pair(multi.back(), single[0]));
		ans.push_back(make_pair(multi[0], single[1]));
		dia += 2;
		a[multi.back()]--, a[multi[0]]--;
		for(int i = 2; i < single.size(); i++){
			while(a[multi.back()] == 0) multi.pop_back();
			ans.push_back(make_pair(multi.back(), single[i]));
			a[multi.back()]--;
		}
	}
	
	cout << "YES" << " " << dia << endl;
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i].first << " " << ans[i].second << endl;
	}
	
	return 0;
}