#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

int p[1010101];

int main(){
	int n;
	scanf("%d", &n);
	ll val=0;
	ll ch=0;
	vector<pair<int, int> > cev;
	vector<pair<int, int> > vev;
	for (int i=1;i<=n;i++){
		scanf("%d", &p[i]);
		
		val+=(ll)abs(p[i]-i);
		if (p[i]>i){
			ch--;
			cev.push_back({p[i]-i, 2});
		}
		else{
			ch++;
			cev.push_back({n-i+p[i], 2});
		}
		cev.push_back({n-i, -2});
		vev.push_back({n-i, abs(1-p[i])});
		vev.push_back({n-i, -abs(n-p[i])+1});
	}
	sort(cev.begin(), cev.end());
	sort(vev.begin(), vev.end());
	ll bv=val;
	int bi=0;
	
// 	cout<<ch<<endl;
	
	int ci=0;
	int vi=0;
	for (int i=0;i<n;i++){
// 		cout<<i<<" "<<val<<endl;
		if (val<bv){
			bv=val;
			bi=i;
		}
		while (ci<(int)cev.size()&&cev[ci].F<=i){
			ch+=(ll)cev[ci].S;
			ci++;
		}
		while (vi<(int)vev.size()&&vev[vi].F<=i){
// 			cout<<"vp "<<vev[vi].S<<endl;
			val+=(ll)vev[vi].S;
			vi++;
		}
		val+=ch;
// 		cout<<i<<" "<<ch<<" "<<val<<endl;
	}
	printf("%lld %d\n", bv, bi);
}