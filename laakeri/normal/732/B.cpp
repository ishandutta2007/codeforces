#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

int a[555];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	a[0]=k;
	int v=0;
	for (int i=1;i<=n;i++){
		int ne=k-a[i]-a[i-1];
		if (ne>0) {
			a[i]+=ne;
			v+=ne;
		}
	}
	cout<<v<<endl;
	for (int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
}