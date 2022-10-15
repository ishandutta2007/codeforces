#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    int lg=0,s=1;
    while(s<n){
        s*=k;
        lg++;
    }
    cout<<lg<<"\n";
    for(int a=1;a<=n;a++){
        for(int b=a+1;b<=n;b++){
            int fuck=0,wao1=a-1,wao2=b-1;
            for(int c=1;c<=lg;c++){
                if(wao1%k!=wao2%k)fuck=c;
                wao1/=k;
                wao2/=k;
            }
            cout<<fuck<<" ";
        }
    }
}