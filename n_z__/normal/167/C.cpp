#include<bits/stdc++.h>
using namespace std;
#define int long long
int f(int x,int y)
{
    if(x<y)swap(x,y);
    return y&&(!f(x%y,y)||1-x/y%(y+1)%2);
}
main() {
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        if(f(x,y))cout<<"First"<<endl;
        else cout<<"Second"<<endl;
    }
}