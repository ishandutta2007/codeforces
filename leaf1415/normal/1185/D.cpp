#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;

llint n;
llint a[200005];
P p[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) p[i] = make_pair(a[i], i);
	sort(p+1, p+n+1);
	
	llint d = p[2].first - p[1].first; bool flag = true;
	for(int i = 1; i <= n-1; i++){
		if(p[i].first != p[1].first + (i-1)*d) flag = false;
	}
	if(flag){
		cout << p[n].second << endl;
		return 0;
	}
	
	d = p[n].first - p[n-1].first, flag = true;
	for(int i = 2; i <= n; i++){
		if(p[i].first != p[2].first + (i-2)*d) flag = false;
	}
	if(flag){
		cout << p[1].second << endl;
		return 0;
	}
	
	if( (p[n].first - p[1].first) % (n-2) ){
		cout << -1 << endl;
		return 0;
	}
	d = (p[n].first - p[1].first) / (n-2);
	int pass = 0, pass_i = 1;
	for(int i = 1; i <= n; i++){
		if(p[i].first != p[1].first + (i-1-pass)*d) pass++, pass_i = p[i].second;
		if(pass >= 2){
			cout << -1 << endl;
			return 0;
		}
	}
	cout << pass_i << endl;
	
	return 0;
}