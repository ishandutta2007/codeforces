#include<bits/stdc++.h>
using namespace std;

int inp[100001];
int main()
{
int n,k;
cin>>n>>k;

for(int i=1;i<=n;i++)cin>>inp[i];

int outp=0;

for(int i=1;i<=n;i++)
   if(inp[i] && inp[i] >= inp[k]) outp++;

cout<<outp<<endl;
}