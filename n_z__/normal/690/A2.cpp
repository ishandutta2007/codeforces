#include<bits/stdc++.h>
using namespace std;
main()
{
    int n;
    cin>>n;
    if(n%2==1)cout<<(n-1)/2;
    else cout<<(n-(1<<((int)log2(n))))/2;
}