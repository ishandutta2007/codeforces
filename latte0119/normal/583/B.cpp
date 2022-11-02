#include<bits/stdc++.h>
using namespace std;
int N;
int a[1000];

int main(){
    cin>>N;
    for(int i=0;i<N;i++)cin>>a[i];
    int sum=0;
    for(int i=0;i<N;i++){
        if(i&1){
            for(int j=N-1;j>=0;j--)if(~a[j]&&sum>=a[j]){
                a[j]=-1;
                sum++;
            }
        }
        else{
            for(int j=0;j<N;j++)if(~a[j]&&sum>=a[j]){
                a[j]=-1;
                sum++;
            }
        }
        if(sum==N){
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}