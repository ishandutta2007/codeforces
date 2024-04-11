#include<bits/stdc++.h>
using namespace std;
const int N=100005;
typedef long long ll;
int n,s;
int main(){
    cin>>n>>s;
    if(s%n) cout<<s/n+1;
    else cout<<s/n;
    return 0;
}