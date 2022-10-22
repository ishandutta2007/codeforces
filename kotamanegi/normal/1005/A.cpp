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
	int n;
	cin >> n;
	int cnt = 0;
	vector<int> hoge;
	REP(i,n){
		int a;
		cin >> a;
		cnt++;
		if(cnt != a){
			hoge.push_back(cnt-1);
			cnt = 1;
		}
	}
	hoge.push_back(cnt);
	cout << hoge.size() << endl;
	REP(i,hoge.size()){
		cout << hoge[i] << " ";
	}
	cout << endl;
	return 0;
}