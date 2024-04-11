#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

int a[2020];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	int v=n/m;
	map<int, int> cnt;
	for (int i=0;i<n;i++){
		cin>>a[i];
		cnt[a[i]]++;
	}
	int c=0;
	for (int i=1;i<=m;i++){
		while (cnt[i]<v){
			for (int j=0;j<n;j++){
				if (cnt[a[j]]>v||a[j]>m){
					cnt[a[j]]--;
					cnt[i]++;
					a[j]=i;
					break;
				}
			}
			c++;
		}
	}
	cout<<v<<" "<<c<<endl;
	for (int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}