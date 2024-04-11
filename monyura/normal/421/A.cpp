#include <iostream>
using namespace std;
int main()
{
int n,cnt[2];
cin>>n>>cnt[0]>>cnt[1];
int A[101];
for (int t=0;t<2;t++)
{
for (int j = 0; j < cnt[t]; j++)
{
int b;
cin>>b;
A[b] = t+1;
}
}
for (int i = 1; i<=n; i++)
cout<<A[i]<<' ';
return 0;
}