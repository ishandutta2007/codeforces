// 

#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n,k;
    string s;
    cin>>n>>k>>s;
    if(k==1){
        for(int i=0;i<n;i++)cout<<k;
        return 0;
    }
    vector<int> z; // z-algorithm moban
    z.push_back(0);
    int l=0,r=0;
    for(int i=1;i<n;i++){
        if(i>r)z.push_back(0);
        else z.push_back(min(z[i-l],r-i+1));
        while(z[i]+i<n&&s[z[i]]==s[z[i]+i])z[i]++;
        if(r<z[i]+i-1){
            l=i;
            r=z[i]+i-1;
        }
    }
    int wa[n+1]={};
    for(int i=1;i<n;i++){
        if((z[i]+i)/i>=k){
            wa[min(n,i*k-1)]++;
            wa[min(n,min(i*(k+1),z[i]+i))]--;
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=wa[i];
        cout<<(ans>0);
    }
}