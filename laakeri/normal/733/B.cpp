#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

int l[101010];
int r[101010];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	int ls=0;
	int rs=0;
	for (int i=0;i<n;i++){
		cin>>l[i]>>r[i];
		ls+=l[i];
		rs+=r[i];
	}
	pair<int, int> v={abs(ls-rs), 0};
	for (int i=0;i<n;i++){
		ls+=r[i]-l[i];
		rs+=l[i]-r[i];
		if (abs(ls-rs)>v.F){
			v={abs(ls-rs), i+1};
		}
		ls+=l[i]-r[i];
		rs+=r[i]-l[i];
	}
	cout<<v.S<<endl;
}