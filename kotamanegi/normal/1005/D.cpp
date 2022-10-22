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
int divide[4][300000] = {};
int main(){
	string s;
	cin >> s;
	divide[0][0] = 1;
	for(int i = 0;i < s.length();++i){
		int hoge = s[i] - '0';
			for(int q = 0;q < 3;++q){
				if(divide[q][i] != 0){
				if((hoge+q)%3 != 0){
					divide[(hoge+q)%3][i+1] = divide[q][i];
				}else{
					divide[(hoge+q)%3][i+1] = divide[q][i]+1;
				}
				}
			}
			for(int q = 0;q < 3;++q){
				divide[0][i+1] = max(divide[0][i+1],divide[q][i+1]);
			}
	}
	cout << max(divide[0][s.length()],max(divide[1][s.length()],divide[2][s.length()]))-1 << endl;
	return 0;
}