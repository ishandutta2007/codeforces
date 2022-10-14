#include<bits/stdc++.h>
using namespace std;
int const N=233333;
int t,n,a[N];
set<int>s;
int main(){
    ios::sync_with_stdio(0);
    for(cin>>t;t--;){
        cin>>n,s.clear();
        for(int i=1;i<=n;i++)
            cin>>a[i],s.insert(a[i]);
        sort(a+1,a+1+n);
        vector<int>t;
        for(int i=1;i<=3;i++)
            t.push_back(a[i]);
        for(int i=max(4,n-2);i<=n;i++)
            t.push_back(a[i]);
        int m=t.size(),flg=1;
        for(int i=0;i<m;i++)
            for(int j=i+1;j<m;j++)
                for(int k=j+1;k<m;k++)
                    flg&=s.count(t[i]+t[j]+t[k]);
        cout<<(flg?"YES\n":"NO\n");
    }
}