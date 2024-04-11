#include<bits/stdc++.h>
using namespace std;

int main()
{
int n;
cin>>n;

int outp=0;
for(int i=1;i<=n;i++)
{
char a, b, c;
cin>>a>>b>>c;

if(a=='+' || b=='+' ||c=='+') outp++;
else outp--;
}

cout<<outp<<endl;
}