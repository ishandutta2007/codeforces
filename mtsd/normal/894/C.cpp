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

int gcd(int v,int b){
	if(v>b) return gcd(b,v);
	if(v==b) return b;
	if(b%v==0) return v;
	return gcd(v,b%v);
}

int main(){
	int n;
	cin >> n;
	VI v(n);
	for(int i=0;i<n;i++){
		cin >> v[i];
	}
	int k = v[0];
	if(k==1){
		cout << 3*n << endl;
		for(int i=0;i<n-1;i++){
			cout << v[i] << " " << v[i] << " " << 1 << " ";
		}
		cout << v[n-1] << " " << v[n-1] << " " << 1 << endl;
	}else{
		bool flag = 0;
		for(int i=1;i<n;i++){
			if(v[i]%k!=0)flag=1;
		}
		if(flag){
			cout << -1 << endl;
		}else{
			cout << 3*n << endl;
			for(int i=0;i<n-1;i++){
				cout << v[i] << " " << v[i] << " " << v[0] << " ";
			}
			cout << v[n-1] << " " << v[n-1] << " " << v[0] << endl;
		}
	}
	return 0;
}