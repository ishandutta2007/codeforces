#include<bits/stdc++.h>
using namespace std;
int main()
{
char a,b;
cin>>a>>b;

char c,d;
bool ok=0;
for(int i=0;i<5;i++)
{
    cin>>c>>d;
    if(a==c||b==d)ok=1;
}
if(ok)cout<<"Yes"<<endl;
else cout<<"No"<<endl;
return 0;
}