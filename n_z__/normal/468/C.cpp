#include<bits/stdc++.h>
using namespace std;
int main(){
    long long x;
    cin>>x;
    cout<<x-(long long)(1e18)*9%x*9%x<<' '<<x-(long long)(1e18)*9%x*9%x+(long long)(1e18)-1;
}