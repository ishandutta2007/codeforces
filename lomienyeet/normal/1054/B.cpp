#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int fuck=-1;
    for(int i=1,fuckfuck;i<=n;i++){
        cin>>fuckfuck;
        if(fuckfuck>fuck+1){
            cout<<i<<"\n";
            return 0;
        }
        fuck=max(fuckfuck,fuck);
    }
    cout<<"-1\n";
    return 0;
}