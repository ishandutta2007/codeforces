#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,one,zero;
string s;

int main(){
    cin>>n;
    cin>>s;
    for(int i=0;i<n;i++){
        if(s[i]=='1')one++;
        else zero++;
    }
    if(zero==one){
        printf("%d\n",2);
        cout<<s[0]<<' ';
        for(int i=1;i<n;i++)
            cout<<s[i];
        cout<<'\n';
    }
    else{
        cout<<1<<'\n'<<s;
    }
}
/*
    Good Luck
        -Lucina
*/