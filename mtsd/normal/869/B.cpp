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
	ll a,b;
	cin >> a >> b;
	ll k = 1;
	if(a==b){
		cout << 1 << endl;
		return 0;
	}
	for(ll i=a+1;i<=b;i++){
		k *= i%10;
		if(k%10==0)break;
	}
	cout << k%10 << endl;
	return 0;
}