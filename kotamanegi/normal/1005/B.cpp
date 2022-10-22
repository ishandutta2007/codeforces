#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <math.h>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <iostream> 
#include<map>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <iomanip>
using namespace std;
#define MAX_MOD 1000000007
#define REP(i,n) for(int i = 0;i < n;++i)
int main(){
	string s,t;
	cin >> s >> t;
	if(s.length() > t.length())swap(s,t);
	int ans = 0;
	reverse(t.begin(),t.end());
	while(t.length() != s.length()){
		t.pop_back();
		ans++;
	}
	reverse(t.begin(),t.end());
	ans += s.length()*2;
	for(int i = t.length()-1;i >= 0;--i){
		if(s[i] != t[i]){
			cout << ans << endl;
			return 0;
		}else ans -= 2;
	}
	cout << ans << endl;
	return 0;
}