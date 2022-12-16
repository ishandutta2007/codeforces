#include<bits/stdc++.h>
using namespace std;

int main()
{
int t;
cin>>t;

for(int i=1;i<=t;i++)
{
    int a, b;
    cin>>a>>b;
    cout<<(b-a%b)%b<<endl;
} 


}