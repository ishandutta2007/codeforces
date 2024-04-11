#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

int isp(int x){
	for (int a=2;a*a<=x;a++){
		if (x%a==0) return 0;
	}
	return 1;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for (int m=1;;m++){
		if (!isp(n*m+1)){
			cout<<m<<endl;
			return 0;
		}
	}
}