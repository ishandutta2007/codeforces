#include <iostream>
#include <cstdio>
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
	int n;
	cin >> n;
	int ans;
	ans = (n/2)*2+(n-n/2);
	cout << ans << endl;
	vector<int>v;
	for(int i=2;i<=n;i+=2){
		v.push_back(i);
	}
	for(int i=1;i<=n;i+=2){
		v.PB(i);
	}
	for(int i=2;i<=n;i+=2){
		v.PB(i);
	}
	for(int i=0;i<v.size()-1;i++){
		printf("%d ",v[i]);
	}
	printf("%d\n",v[v.size()-1]);
	return 0;
}