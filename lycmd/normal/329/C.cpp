#include<bits/stdc++.h>
using namespace std;
int const N=233333;
int n,m,a[N];
set<pair<int,int> >s;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
auto gen=[](int l,int r){return rnd()%(r-l+1)+l;};
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;cin>>x>>y;
		s.insert({x,y});
		s.insert({y,x});
	}
	for(int i=1;i<=n;i++)
		a[i]=i;
	for(int t=50;t--;){
		shuffle(a+1,a+1+n,rnd),a[n+1]=a[1];
		int flg=1;
		for(int i=1;flg&&i<=m;i++)
			flg&=!s.count({a[i],a[i+1]});
		if(flg){
			for(int i=1;i<=m;i++)
				cout<<a[i]<<" "<<a[i+1]<<"\n";
			return 0;
		}
	}
	cout<<"-1\n";
}