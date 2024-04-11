#include <bits/stdc++.h>
using namespace std;
#define int long long
main(){
	int t;
	cin>>t;
	while(t--){
		int l=100000000000001,r=0,s=1;
		while(l>r+1){
            int x=r+1.5+0.5*(l-r-2)*s/(s+l);
            x=max(min(x,s),r);
            cout<<"? "<<x<<endl;
			string res;
			cin>>res;
            if(res=="Lucky!")r=x,s+=x;
			else l=x,s-=x;
		}
		cout<<"! "<<r<<endl;
	}
}