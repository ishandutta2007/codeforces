#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int m;
	cin>>m;
	vector<int> v;
	int s2=0;
	int s5=0;
	for (int i=1;;i++){
		int x=i;
		while (x%2==0){
			s2++;
			x/=2;
		}
		while (x%5==0){
			s5++;
			x/=5;
		}
		if (min(s2, s5)==m){
			v.push_back(i);
		}
		if (min(s2, s5)>m) break;
	}
	cout<<v.size()<<endl;
	for (int vv:v){
		cout<<vv<<" ";
	}
	cout<<endl;
}