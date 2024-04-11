#include<bits/stdc++.h>
using namespace std;

int main()
{
int n;
cin>>n;
string inp;
cin>>inp;

int outp=0;

for(int i=1; i<n; i++)if(inp[i] == inp[i-1])outp++;

cout<< outp <<endl;
}