#include <bits/stdc++.h>
using namespace std;
int main(){
    long long int t;
    cin>>t;
    for(long long int i=0;i<t;i++){
        long long int a,b,c,d;
        cin>>a>>b>>c>>d;
        c-=a;
    	d-=b;
    	c=abs(c);
    	d=abs(d);
    	long long int x=min(c,d);
    	long long int y=max(c,d);
    	unsigned long long int ans=x*x+(y-x)*x;
    	ans++;
        cout<<ans<<"\n";
    }
}