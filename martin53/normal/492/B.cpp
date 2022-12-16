#include<bits/stdc++.h>
using namespace std;

int main()
{
int n, l;
cin>>n>>l;
vector<int> in={} ;

for(int i=1;i<=n;i++)
{
 int cur;
cin>>cur; 
 in.push_back(cur) ;
}
sort(in.begin(), in.end());

double outp=max(in[0], l-in.back());

for(int i=1;i<in.size();i++)
outp=max((1.0*in[i]-in[i-1])/2, outp) ;

printf("%.9f", outp);
}