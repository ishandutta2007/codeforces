#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
LL k,w,n;
int main()
{
    cin>>k>>n>>w;
    cout<<max(0LL,k*(1+w)*w/2-n)<<endl;
    return 0;
}