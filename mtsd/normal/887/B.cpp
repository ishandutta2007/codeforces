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
	int n;
	cin >> n;
	vector<set<int> > v(n);
	for(int i=0;i<n;i++){
		for(int j=0;j<6;j++){
			int tmp;
			cin >> tmp;
			v[i].insert(tmp);
		}
	}
	for(int i=1;i<10;i++){
		bool flag = 1;
		for(int j=0;j<n;j++){
			if(v[j].count(i)!=0){
				flag = 0;
			}
		}
		if(flag){
			cout << i-1 << endl;
			return 0;
		}
	}
	for(int i=10;i<100;i++){
		bool flag = 1;
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				if(j==k)continue;
				if(v[j].count(i/10)!=0&&v[k].count(i%10)!=0){
					flag = 0;
				}
			}
		}
		if(flag){
			cout << i-1 << endl;
			return 0;
		}
	}
	for(int i=100;i<1000;i++){
		bool flag = 1;
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				for(int l=0;l<n;l++){
					if(j==k||j==l||k==l)continue;
					if(v[j].count(i/100)!=0&&v[k].count((i/10)%10)!=0&&v[l].count(i%10)!=0){
						flag = 0;
					}
				}
			}
		}
		if(flag){
			cout << i-1 << endl;
			return 0;
		}
	}
	cout << 999 << endl;
	return 0;
}