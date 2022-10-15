#include <bits/stdc++.h>
using namespace std;
int N;
double K,sum;
double fk(int x){
    return (sum+K*x)/(N+x);
}
int main(){
    cin>>N>>K;
    sum=0;
    for(int i=1;i<=N;i++){
        int x;
        cin>>x;
        sum+=x;
    }
    int ans;
    for(int l=0,r=100005;l<=r;){
        int M=(l+r)/2;
        if(fk(M)>=K-0.5){
            ans=M;
            r=M-1;
        }
        else l=M+1;
    }
    cout<<ans<<"\n";
    return 0;
}