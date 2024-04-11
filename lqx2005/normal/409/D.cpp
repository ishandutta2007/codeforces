#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=200005;
ll n;
bool check[N]={0,1,0,0,1,0,1,0,1,1,1,0,0,1,0,1,0};
int main()
{
    cin>>n;
    cout<<check[n]<<endl;
    return 0;
}