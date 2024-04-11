#include<bits/stdc++.h>
using namespace std;

int n;
int a[2000];
int main(){
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    int b[2000]={0};
    int cur=1;

    for(int i=2000;i>0;i--){
        int next=cur;
        for(int j=0;j<n;j++){
            if(a[j]==i){
                b[j]=cur;
                next++;
            }
        }
        cur=next;
    }

    for(int i=0;i<n;i++)cout<<b[i]<<" ";cout<<endl;
    return 0;
}