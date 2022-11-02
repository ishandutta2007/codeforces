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
	//n=50000;
	vector<int> a(n);
	for (int i=0;i<n;i++){
		cin>>a[i];
		//a[i]=rand()%(1e9);
	}
	sort(a.rbegin(), a.rend());
	int mi=0;
	int ma=1e9;
	int v=ma;
	while (mi<=ma){
		int mid=(mi+ma)/2;
		set<int> u;
		int fa=0;
		for (int i=0;i<n;i++){
			int t=a[i];
			int f=0;
			while (t>0){
				if (t<=mid&&u.count(t)==0){
					u.insert(t);
					f=1;
					break;
				}
				t/=2;
			}
			if (f==0){
				fa=1;
				break;
			}
		}
		if (fa){
			mi=mid+1;
		}
		else{
			ma=mid-1;
			v=mid;
		}
	}
	set<int> uu;
	for (int i=0;i<n;i++){
		int t=a[i];
		while (t>0){
			if (t<=v&&uu.count(t)==0){
				uu.insert(t);
				cout<<t<<" ";
				break;
			}
			t/=2;
		}
	}
	cout<<endl;
}