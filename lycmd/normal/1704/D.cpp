#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=300010;
int t,n,m;
vector<vector<int> >a;
int calc(const vector<int>&x){
	int s=0,n=x.size();
	vector<int>y={0};
	for(int i=0;i<n;i++)
		y.push_back(y.back()+x[i]),s+=y.back();
	return s;
}
int check(const vector<int>&x,const vector<int>&y){
	return abs(calc(x)-calc(y));
}
signed main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n>>m;
		a.clear();
		a.resize(n+1);
		for(int i=1;i<=n;i++)
			a[i].resize(m+1,0);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>a[i][j];
		int f1=check(a[1],a[2]),f2=check(a[2],a[3]);
		if(f1)
			cout<<(1+!!f2)<<" "<<check(a[1],a[2])<<"\n";
		else
			for(int i=3;i<=n;i++)
				if(check(a[1],a[i]))
					cout<<i<<" "<<check(a[1],a[i])<<"\n";
	}
}