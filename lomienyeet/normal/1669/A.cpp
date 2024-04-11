// i am just doing this to lower my TLE bot virtual solve speed

#include <bits/stdc++.h>
using namespace std;
#define int long long
void eat(){
    int x;
    cin>>x;
    cout<<"Division ";
    if(x>=1900)cout<<"1\n";
    else if(x>=1600)cout<<"2\n";
    else if(x>=1400)cout<<"3\n";
    else cout<<"4\n";
}
signed main(){
    int t=1;
    cin>>t;
    while(t--)eat();
}