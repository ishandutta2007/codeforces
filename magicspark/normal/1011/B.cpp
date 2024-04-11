#include<bits/stdc++.h>
using namespace std;
const int inf=1<<30;
int a[101];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x;
		cin>>x;
		a[x]++;
	}
	for(int i=1;i<=m+10;i++){
		int res=0;
		for(int j=0;j<101;j++){
			res+=(a[j]/i);
		}
		if(res<n){
			cout<<i-1<<endl;
			break;
		}
	}
	return 0;
}