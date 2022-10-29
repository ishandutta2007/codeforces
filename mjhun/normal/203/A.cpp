#include <iostream>
using namespace std;

int main(){
	int x,t,a,b,da,db,i,j;
	bool r;
	cin>>x>>t>>a>>b>>da>>db;
	r=x==0;
	for(i=0;i<=t&&!r;++i){
		for(j=0;j<=t&&!r;++j){
			if(i==t&&j==t);
			else if(i==t)
				r= x==b-db*j;
			else if(j==t)
				r= x==a-da*i;
			else
				r= x==a-da*i+b-db*j;
		}
	}
	
	cout<<(r?"YES":"NO")<<endl;
	return 0;		
}