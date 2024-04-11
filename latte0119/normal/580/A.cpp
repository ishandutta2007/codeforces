#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];

    int cur=0;
    int ans=0;
    while(cur<n){
        int next=cur+1;
        while(next<n&&a[next]>=a[next-1])next++;
        ans=max(ans,next-cur);
        cur=next;
    }
    cout<<ans<<endl;
    return 0;
}