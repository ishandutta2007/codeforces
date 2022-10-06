#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007

int main(){
	string s;
	cin >> s;
	int x = -1;
	int c = 0;
	for(int i=0;i<s.size();i++){
		if(x==-1&&s[i]=='1'){
			x = i;
		}else if (x!=-1&&s[i]=='0'){
			c++;
		}
	}
	if(c>=6){
		cout << "yes" << endl;
	}else{
		cout << "no" << endl;
	}
	return 0;
}