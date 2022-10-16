#include<bits/stdc++.h>
using namespace std;
void pre(){}
int check(int i,int j){
    if( ( i - (j*(j-1)) /2 )%j==0 ){
        return ( i  - (j*(j-1))/2 )/j ;
    }
    return 0;
}
set<int>s;
int mex(){
    int i = 0;
    while(true){
        if(s.find(i)==s.end()){
            return i;
        }
        i++;
    }    
}
void solve(){
    int n;cin>>n;
    int dp[100001]{0};
    int val[100001]{0};
    dp[1]=0;dp[2]=0;val[1]=-1;val[2]=-1;
    int va=0;
    for(int i=3;i<=100000;i++){
        va=1000000000;
        s.clear();
        int oo =0;
        for(int j=2;j<=(sqrt(8*i+1)+1)/2;j++){
            auto p = check(i,j);
            if(p<=0)   continue;
            oo=0;
            for(int i=0;i<j;i++){
                oo^=dp[p+i];
            }
            //cout<<i<<" "<<j<<" "<<oo<<"\n";
            if(oo==0){
                va=min(j,va);
            }
            s.insert(oo);
        }
        dp[i]=mex();
        if(dp[i]!=0){
            val[i]=va;
        }else{
            val[i]=-1;
        }
    }
    cout<<val[n]<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    //cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}