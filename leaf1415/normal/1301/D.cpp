#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <utility>
#define llint long long
#define inf 1e18

using namespace std;
typedef pair<llint, string> P;

llint h, w, k;
vector<P> ans;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> h >> w >> k;
	
	if(k > 2*(w-1)*h + 2*(h-1)*w){
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	
	llint x;
	for(int i = 1; i <= h-1; i++){
		x = min(k, w-1);
		ans.push_back(P(x, "R"));
		k -= x;
		if(k == 0) goto end;
		
		x = min(k, w-1);
		ans.push_back(P(x, "L"));
		k -= x;
		if(k == 0) goto end;
		
		x = min(k, 1LL);
		ans.push_back(P(x, "D"));
		k -= x;
		if(k == 0) goto end;
	}
	
	x = min(k, w-1);
	ans.push_back(P(x, "R"));
	k -= x;
	if(k == 0) goto end;
	
	for(int i = 1; i <= w-1; i++){
		x = min(k, h-1);
		ans.push_back(P(x, "U"));
		k -= x;
		if(k == 0) goto end;
		
		x = min(k, h-1);
		ans.push_back(P(x, "D"));
		k -= x;
		if(k == 0) goto end;
		
		x = min(k, 1LL);
		ans.push_back(P(x, "L"));
		k -= x;
		if(k == 0) goto end;
	}
	
	x = min(k, h-1);
	ans.push_back(P(x, "U"));
	k -= x;
	if(k == 0) goto end;
	
	end:;
	vector<P> tmp = ans;
	ans.clear();
	for(int i = 0; i < tmp.size(); i++){
		if(tmp[i].first > 0) ans.push_back(tmp[i]);
	}
	
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i].first << " " << ans[i].second << "\n";
	}
	flush(cout);
	
	return 0;
}