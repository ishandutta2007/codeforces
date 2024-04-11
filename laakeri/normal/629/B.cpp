#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

int m[1000];
int f[1000];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for (int i=0;i<n;i++){
		char c;
		int l,r;
		cin>>c>>l>>r;
		if (c=='M') {
			m[l]++;
			m[r+1]--;
		}
		else{
			f[l]++;
			f[r+1]--;
		}
	}
	int mm=0;
	int ff=0;
	int v=0;
	for (int i=0;i<400;i++){
		mm+=m[i];
		ff+=f[i];
		v=max(v, min(mm, ff));
	}
	cout<<v*2<<endl;
}