#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    int x=0;
    for(int i=0,u;i<n;i++){
        cin>>u;
        x+=(u>k);
    }
    cout<<x+n<<"\n";
}