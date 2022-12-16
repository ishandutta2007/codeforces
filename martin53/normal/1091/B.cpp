#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
int n;
pair<int,int> ob[nmax];
int main()
{
cin>>n;
long long sum_x=0,sum_y=0;
int x,y;
for(int i=1;i<=2*n;i++)
{
    cin>>x>>y;
    sum_x=sum_x+x;
    sum_y=sum_y+y;
}

cout<<sum_x/(n)<<" "<<sum_y/(n)<<endl;
return 0;
}