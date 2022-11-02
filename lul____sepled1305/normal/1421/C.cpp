#include<bits/stdc++.h>
using namespace std;
string s;
int n,i,j,k;

int main()
{
    cin>>s;
    n = s.size();
    cout<<4<<endl;
    cout<<"L "<<n-1<<endl;
    cout<<"L "<<2<<endl;
    cout<<"R "<<2<<endl;
    cout<<"R "<<4*n-5<<endl;
}