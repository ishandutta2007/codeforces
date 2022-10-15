#include <bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c,d,e;
	cin>>a>>b>>c>>d>>e;
	int ans=0;
	string gay="";
	while(d>0){
		if(a>e||b>=d){
			d-=b;
			a-=e;
			gay+="STRIKE\n";
		}
		else{
			a+=c-e;
		    gay+="HEAL\n";
		}
		ans++;
	}
	cout<<ans<<"\n"<<gay;
}