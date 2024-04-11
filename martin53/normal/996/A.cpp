#include<bits/stdc++.h>
using namespace std;

int main()
{
int n, outp=0;
cin>>n;

vector<int> seen={100, 20, 10, 5, 1};

for(auto w:seen)
{
    outp+=n/w;
    n=n%w;
} 
cout<<outp<<endl;
}