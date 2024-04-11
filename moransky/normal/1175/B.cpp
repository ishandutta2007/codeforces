#include <cstdio>
#include <iostream>
#include <string>
#include <stack> 
using namespace std;
typedef long long LL;
const LL INF = (1ll << 32) - 1; 
LL n = 0, loop = 1;
stack<int> s;
string ch;
int x, flag = 0;
int main(){
	ios::sync_with_stdio(false);
	int T; cin >> T;
	while(T--){
		cin >> ch;
		if(ch == "add"){ 
			if(loop > INF){
				cout << "OVERFLOW!!!" << endl;
				return 0;
			}
			n += loop;
		}else if(ch == "for"){
			cin >> x;
			if(loop > INF) {
				flag++;
				continue;
			}
			s.push(x);
			loop *= x;
		}else if(ch == "end"){
			if(flag) {
				flag --;
				continue;
			}
			loop /= s.top();
			s.pop(); 
		}
		if(n > INF){
			cout << "OVERFLOW!!!" << endl;
			return 0;
		}
	}
	cout << n << endl;
	return 0;
}