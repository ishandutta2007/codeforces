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
sort(in.begin(), in.end());

for(auto w:in) 
    cout<<w<<" ";
}