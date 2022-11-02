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
	int t=4*60;
	int n,k;
	cin>>n>>k;
	t-=k;
	int v=0;
	for (int i=1;i<=n;i++){
		if (5*i<=t){
			v++;
			t-=5*i;
		}
	}
	cout<<v<<endl;
}