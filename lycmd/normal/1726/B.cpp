#include<bits/stdc++.h>
using namespace std;
int t,n,m;
int main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n>>m;
		if(n==1&&m==1)
			cout<<"Yes\n1\n";
		else if(n==2&&m==2)
			cout<<"Yes\n1 1\n";
		else if(m<n||n&1&&m+n-1<2||~n&1&&((m-n+2)/2<1||(m-n+2)%2))
			cout<<"No\n";
		else{
			cout<<"Yes\n";
			for(int i=n-1-(~n&1);i--;)
				cout<<"1 ";
			if(n&1)
				cout<<m-n+1<<"\n";
			else
				cout<<(m-n+2)/2<<" "<<(m-n+2)/2<<"\n";
		}
	}
}