#define  _CRT_SECURE_NO_WARNINGS
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
#include <iomanip>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
using namespace std;
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
#define LONG_INF 100000000000000
int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int a=0, b=0;
	REP(i, s.length()) {
		if (s[i] == 'A')a++;
		else b++;
	}
	if (a == b) {
		cout << "Friendship" << endl;
	}
	else if (a > b) cout << "Anton" << endl;
	else cout << "Danik" << endl;
}