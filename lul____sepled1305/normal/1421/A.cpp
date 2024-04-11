#include<bits/stdc++.h>
using namespace std;
int T;

int main()
{
    cin>>T;
    while(T--)
    {
        int cur = 2, i,a,b;
        cin>>a>>b;
        if(a > b) swap(a,b);
        int nu1 = a^b;
        cout<<nu1<<endl;
    }
}