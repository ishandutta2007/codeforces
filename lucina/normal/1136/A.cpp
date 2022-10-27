#include<bits/stdc++.h>
using namespace std;
int a[105],b[105],n,s;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    cin>>a[i]>>b[i];
    cin>>s;
    for(int i=1;i<=n;i++){
        if(s>=a[i]&&s<=b[i]){
            printf("%d\n",n-i+1);
            return 0;
        }
    }
}