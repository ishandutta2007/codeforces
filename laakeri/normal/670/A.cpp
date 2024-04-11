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
	int n;
	cin>>n;
	cout<<(n/7)*2+max(0, n%7-5)<<" "<<(n/7)*2+min(2, n%7)<<endl;
}