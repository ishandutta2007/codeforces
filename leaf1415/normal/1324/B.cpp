#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#define llint long long

llint T;
llint n;
llint a[5005];
bool cnt[5005];

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i];
		for(int i = 1; i <= n; i++) cnt[i] = false;
		for(int i = 1; i <= n; i++){
			for(int j = i+1; j <= n; j++){
				if(cnt[a[j]]){
					cout << "YES" << endl;
					goto end;
				}
			}
			cnt[a[i]] = true;
		}
		cout << "NO" << endl;
		end:;
	}
	
	return 0;
}