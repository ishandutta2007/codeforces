#include<bits/stdc++.h>
using namespace std;

int main()
{
int n=4;
set<int> in={} ;
for(int i=1;i<=n;i++)
{
    int cur;
    cin>>cur;
    in.insert(cur);
} 
cout<<4-in.size()<<endl;
}