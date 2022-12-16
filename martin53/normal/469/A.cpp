#include<bits/stdc++.h>
using namespace std;

int main()
{
int n;
cin>>n;
set<int> in={} ;
for(int t=1;t<=2;t++)
{
    int SZ;
    cin>>SZ;
    for(int i=1;i<=SZ;i++)
    { 
    int cur; 
    cin>>cur; 
    in.insert(cur);
    } 
} 

if(in.size()==n)cout<<"I become the guy."<<endl;
else cout<<"Oh, my keyboard!"<<endl;
}