#include<bits/stdc++.h>
using namespace std;

int N;
int d[10000];
int main(){
    cin>>N;
    for(int i=0;i<N-1;i++){
        int a,b;
        cin>>a>>b;
        a--;b--;
        d[a]++;d[b]++;
    }

    long long ans=0;
    for(int i=0;i<N;i++)ans+=d[i]*(d[i]-1)/2;
    cout<<ans<<endl;
    return 0;
}