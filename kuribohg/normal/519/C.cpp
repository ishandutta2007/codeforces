#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int MAXN=100010;
int n,m;
int main()
{
    cin>>n>>m;
    cout<<min(min(n,m),(n+m)/3)<<endl;
    return 0;
}