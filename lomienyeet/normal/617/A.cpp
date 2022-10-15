#include <bits/stdc++.h>
using namespace std;
int main(){
    long long N;
    cin>>N;
    int ans=N/5;
    if(N%5!=0)ans++;
    cout<<ans<<"\n";
	return 0;
}