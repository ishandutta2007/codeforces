#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mxN=2e5+5;
struct query{
    int op,l,r;
}que[mxN];
signed main(){
    int n,q,m;
    cin>>n>>q>>m;
    int arr[n+1];
    for(int i=1;i<=n;i++)cin>>arr[i];
    for(int i=1;i<=q;i++)cin>>que[i].op>>que[i].l>>que[i].r;
    reverse(que+1,que+q+1);
    while(m--){
        int x;
        cin>>x;
        for(int j=1;j<=q;j++){
            if(que[j].l<=x&&x<=que[j].r){
                if(que[j].op==1){
                    if(que[j].l==x)x=que[j].r;
                    else x--;
                }
                else x=que[j].l+que[j].r-x;
            }
        }
        cout<<arr[x]<<" ";
    }
}