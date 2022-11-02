#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

int a[202020];

int ma[202020];

int v[202020];

vector<int> co[202020];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	ll vv=0;
	for (int i=1;i<n;i++){
		co[__gcd(i, n)].push_back(i);
	}
	for (int j=1;j<n;j++){
		if (n%j==0){
			if (co[j].size()>0){
				for (int i=0;i<j;i++){
					ma[i]=0;
				}
				for (int i=0;i<n;i++){
					ma[i%j]=max(ma[i%j], a[i]);
				}
				int o=0;
				for (int i=0;i<n;i++){
					if (a[i]<ma[i%j]){
						o=0;
					}
					else{
						o++;
					}
				}
				int i2=0;
				vector<int> add(co[j].size());
				while (i2<(int)co[j].size()&&o>=co[j][i2]){
					i2++;
				}
				for (int i=0;i<n;i++){
					if (a[i]<ma[i%j]){
						o=0;
						i2=0;
					}
					else{
						o++;
					}
					while (i2<(int)co[j].size()&&o>=co[j][i2]){
						i2++;
					}
					if (i2>0){
						add[i2-1]++;
					}
				}
				ll ad=0;
				for (int i=(int)co[j].size()-1;i>=0;i--){
					ad+=(ll)add[i];
					vv+=ad;
				}
			}
		}
	}
	cout<<vv<<endl;
}