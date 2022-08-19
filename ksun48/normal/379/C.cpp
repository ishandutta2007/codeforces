#include<iostream>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long LL;

int main(){
	int n;
	cin >> n;
	pair<int,int> stuff[n];
	for(int i = 0; i < n; i++) cin >> stuff[i].first;
	for(int i = 0; i < n; i++) stuff[i].second = i;
	int ans[n];
	sort(stuff, stuff+n);
	int cur = 1;
	for(int i = 0; i < n; i++){
		stuff[i].first = max(stuff[i].first, cur);
		cur = stuff[i].first+1;
	}
	for(int i = 0; i < n; i++) ans[stuff[i].second] = stuff[i].first;
	for(int i = 0; i < n; i++) cout << ans[i] << " ";
	cout << endl;
}