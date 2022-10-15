// maybe i am just stupid, but this task seems not so intuitive

#include <bits/stdc++.h>
using namespace std;  
int main(){
    int b,d;
    string a,c;
    cin>>b>>d>>a>>c;
    int st[30][105],dp[30][105];
    memset(st,0,sizeof st);
    memset(dp,0,sizeof dp);
    for(int i=0;i<c.length();i++){
        int ptr=i;
        for(int j=0;j<a.length();j++){
            if(a[j]==c[ptr%c.length()])ptr++;
        }
        st[0][i]=ptr%c.length();
        dp[0][i]=ptr/c.length();
    }
    for(int i=1;i<30;i++){
        for(int j=0;j<c.length();j++){
            st[i][j]=st[i-1][st[i-1][j]];
            dp[i][j]=dp[i-1][j]+dp[i-1][st[i-1][j]];
        }
    }
    int ptr=0,s=0;
    for(int i=0;i<30;i++){
        if(b&(1<<i)){
            s+=dp[i][ptr];
            ptr=st[i][ptr];
        }
    }
    cout<<s/d<<"\n";
}