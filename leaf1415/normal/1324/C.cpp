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

using namespace std;

llint T;
llint n;
string s;

bool check(llint d)
{
	if(d >= n+1) return true;
	llint pre = 0;
	for(int i = 1; i <= n+1; i++){
		if(s[i] == 'R'){
			if(i-pre > d) return false;
			pre = i;
		}
	}
	return true;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> s;
		n = s.size();
		s = "#" + s + "R";
		llint ub = n+2, lb = -1, mid;
		while(ub-lb>1){
			mid = (ub+lb)/2;
			if(check(mid)) ub = mid;
			else lb = mid;
		}
		cout << ub << "\n";
	}
	flush(cout);
	
	return 0;
}