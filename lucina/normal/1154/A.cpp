#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int a[4];
int main(){
    for(int i=0;i<4;i++)
        cin>>a[i];
    sort(a,a+4);
    for(int i=0;i<3;i++){
        cout<<a[3]-a[i]<<' ';
    }
}