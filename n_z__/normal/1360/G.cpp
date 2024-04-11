#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int t;
	cin>>t;
	while(t--){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		if(a*c==b*d){
			puts("YES");
			for(int x=0;x<a;x++){
			for(int y=1;y<=b;y++)
			if((x*c+y)%b<c)cout<<1;
			else cout<<0;
			cout<<endl;}
		}
		else puts("NO");
	}
}