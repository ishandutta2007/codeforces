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
#include <utility>
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define PI 3.141592653589793238

using namespace std;
typedef pair<llint, llint> P;

llint T;
llint n, k;
string res;

string compare(llint x, llint y)
{
	string ret;
	cout << "? 1 1" << endl;
	cout << x << endl;
	cout << y << endl;
	
	cin >> ret;
	if(ret == "WASTED") exit(0);
	return ret;
}

void output(llint x)
{
	cout << "! " << x << endl;
}

llint calc(llint l, llint r)
{
	if(l == r) return l;
	llint len = r-l+1;
	
	llint keta = 0;
	for(llint t = len; t; t/=2) keta++;
	keta--;
	
	llint ret = 0;
	for(int i = keta; i >= 0; i--){
		if(ret + (1<<i) > len) continue;
		ret += 1<<i;
		cout << "? " << ret << " " << ret << endl;
		for(int j = 1; j <= ret; j++) cout << j << " "; cout << endl;
		for(int j = 0; j < ret; j++) cout << l+j << " "; cout << endl;
		cin >> res;
		if(res == "FIRST") ret -= 1<<i;
	}
	return l + ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	srand(time(NULL));
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> k;
		
		llint len = 1;
		for(int i = 0; i < 20; i++){
			llint x = rand()%(n-1)+2;
			res = compare(1, x);
			if(res == "SECOND"){
				output(1);
				goto end;
			}
		}
		
		while(1){
			if(n <= 2*len){
				output(calc(len+1, n));
				break;
			}
			cout << "? " << len << " " << len << endl;
			for(int i = 1; i <= len; i++) cout << i << " "; cout << endl;
			for(int i = 1; i <= len; i++) cout << len+i << " "; cout << endl;
			cin >> res;
			if(res == "FIRST"){
				output(calc(len+1, 2*len));
				break;
			}
			if(res == "WASTED") exit(0);
			len *= 2;
		}
		end:;
	}
	
	return 0;
}