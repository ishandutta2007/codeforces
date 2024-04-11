#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    cin>>n;
    if(n==1)
    {
        cout<<"-1";
    }
    if(n>1)
    {
        printf("%.0f %.0f",sqrt(n)+1,sqrt(n)+1);
    }
    return 0;
}