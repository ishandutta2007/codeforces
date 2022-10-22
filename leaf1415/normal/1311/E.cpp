#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <stack>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;

llint T;
llint n, d;
llint cnt[5005];
vector<llint> vec[5005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> d;
		if(d > n*(n-1)/2){
			cout << "NO" << "\n";
			continue;
		}
		
		for(int i = 0; i <= n+2; i++) cnt[i] = 0;
		llint rem = n, dsum = 0;
		for(int i = 0; ; i++){
			for(int j = 0; j < (1<<i); j++){
				if(rem <= 0) goto end;
				cnt[i]++;
				rem--;
				dsum += i;
			}
		}
		end:;
		
		rem = d - dsum;
		if(rem < 0){
			cout << "NO" << "\n";
			continue;
		}
		
		stack<llint> stk;
		for(int i = 0; i <= n+2; i++){
			for(int j = 0; j < cnt[i]-1; j++){
				stk.push(i);
			}
		}
		
		while(rem > 0){
			llint x = stk.top();
			stk.pop();
			cnt[x]--;
			cnt[x+1]++;
			if(cnt[x+1] >= 2) stk.push(x+1);
			rem--;
		}
		
		llint id = 1;
		for(int i = 0; i <= n+2; i++) vec[i].clear();
		for(int i = 0; i <= n+2; i++){
			for(int j = 0; j < cnt[i]; j++){
				vec[i].push_back(id++);
			}
		}
		
		cout << "YES" << "\n";
		for(int i = 1; i <= n+2; i++){
			if(cnt[i] == 0) break;
			for(int j = 0; j < vec[i].size(); j++){
				cout << vec[i-1][j/2] << " ";
			}
		}
		cout << "\n";
	}
	flush(cout);
	
	return 0;
}