#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <map>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;
 
typedef long long int64;
 
const int INF = 0x3f3f3f3f;
 
map<int64,string> exps;
 
int declen(int64 x){
    int ret = 0;
    while(x > 0){
        x /= 10;
        ret++;
    }
    return ret;
}
 
int main(){
    int64 n;
    cin >> n;
    string ans = to_string(n);
    //clog << anslen << endl;
    for(int64 i = 2;i*i <= n;i++){
        int64 now = i;
        for(int j = 2;now * i <= n;j++){
        	//clog << i << ' ' << j << endl;
            now *= i;
            string tmp = to_string(i) + '^' + to_string(j);
            if(exps.find(now) == exps.end() || exps[now].length() > tmp.length()){
            	if(tmp.length() < declen(now)){
            		exps[now] = tmp;
            	}
            }
        }
    }
    for(auto i : exps){
    	int64 mul = n / i.first;
    	string Mul = (mul > 1)?(((exps.find(mul) != exps.end())?(exps[mul]):to_string(mul)) + "*"):("");
    	int64 add = n % i.first;
    	string Add = (add > 0)?("+" + ((exps.find(add) != exps.end())?(exps[add]):to_string(add))):("");
    	string tmp = Mul + (i.second) + Add;
    	if(tmp.length() < ans.length()){
    		ans = tmp;
    	}
    }
    cout << ans << endl;
}