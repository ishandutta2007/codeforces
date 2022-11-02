#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

int id[101010];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	cin>>n>>k;
	for (int i=0;i<n;i++){
		cin>>id[i];
	}
	for (int i=1;;i++){
		if (k<=i){
			cout<<id[k-1]<<endl;
			return 0;
		}
		k-=i;
	}
}