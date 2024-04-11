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
	map<int,int> hogea;
	REP(i,n){
		int b;
		cin >> b;
		hogea[b]++;
	}
	int ans = 0;
	for(auto i = hogea.begin();i != hogea.end();++i){
		int a = i -> first;
		int b = i -> second;
		long long geko = 1;
		for(int i = 0;geko < 10000000000;i++){
			geko *= 2;
			if((b > 1||geko-a != a)&&hogea.find(geko-a) != hogea.end()){
				geko = 0;
				break;
			}
		}
		if(geko != 0) ans += b;
	}
	cout << ans << endl;
	return 0;
}