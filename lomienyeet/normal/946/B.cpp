#include <bits/stdc++.h>
using namespace std;
int main(){
    long long a,b;
    cin>>a>>b;
    while(a&&b&&(a>=b*2||b>=a*2)){
        if(a&&b&&a>=b*2)a%=b*2;
        if(a&&b&&b>=a*2)b%=a*2;
    }
    cout<<a<<" "<<b<<"\n";
	return 0;
}