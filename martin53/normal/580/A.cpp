#include<bits/stdc++.h>
using namespace std;

int main()
{
int n;
cin>>n;
vector<int> in={} ;
for(int i=1;i<=n;i++)
{
    int cur;
    cin>>cur;
    in.push_back(cur);
} 


int cnt=1, outp=1;

for(int i=1;i<n;i++)
{
    if(in[i-1]<=in[i])cnt++;
    else cnt=1;
    outp=max(outp, cnt);
}
cout<<outp<<endl;
}