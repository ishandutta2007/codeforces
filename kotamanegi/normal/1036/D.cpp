#include <bits/stdc++.h>
using namespace std;

int main(){
    iostream::sync_with_stdio(false);
    int N;cin>>N;
    vector<long long> A(N+1);
    A[0]=0LL;
    for(int i=1;i<N+1;i++){
        long long a;cin>>a;
        A[i]=A[i-1]+a;
    }
    int M;cin>>M;
    vector<long long> B(M+1);
    B[0]=0LL;
    for(int i=1;i<M+1;i++){
        long long b;cin>>b;
        B[i]=B[i-1]+b;
    }
    int ans=0;
    if(A[N]==B[M]){
        int i;
        int j=1;
        for(i=1;i<N+1;i++){
            while(j!=M and A[i]>B[j]){
                j+=1;
            }
            if(A[i]==B[j]){
                ans+=1;
            }
        }
    }
    else{
        ans=-1;
    }
    cout<<ans<<endl;
}