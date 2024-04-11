#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        int N,X;
        cin>>N>>X;
        int arr[N];
        int even=0,odd=0,sum=0;
        for(int i=0;i<N;i++){
            cin>>arr[i];
            sum+=arr[i];
            if(arr[i]%2)odd++;
            else even++;
        }
        sum%=2;
        if(N==X)cout<<(sum?"Yes\n":"No\n");
        else if(odd and even)cout<<"Yes\n";
        else cout<<(odd&&X%2?"Yes\n":"No\n");
    }
}