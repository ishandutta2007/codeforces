#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

set<int> ua[303030];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,q;
	cin>>n>>q;
	set<int> ur;
	int i2=1;
	for (int i=0;i<q;i++){
		int t,x;
		cin>>t>>x;
		if (t==1){
			ur.insert(i2);
			ua[x].insert(i2);
			i2++;
		}
		else if(t==2){
			while ((int)ua[x].size()>0){
				int te=*ua[x].begin();
				ur.erase(te);
				ua[x].erase(te);
			}
		}
		else{
			while ((int)ur.size()>0&&(*ur.begin())<=x){
				ur.erase(ur.begin());
			}
		}
		cout<<ur.size()<<'\n';
	}
}