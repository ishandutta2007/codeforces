#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n;
vector<int> a;
vector<long long> b;
int main(){
    scanf("%d",&n);
    int x=sqrt(n);
    for(int i=x;i>=1;i--){
        if(n%i==0){
            a.push_back(i);
            if(i*i!=n)
            a.push_back(n/i);
        }
    }
    sort(a.begin(),a.end());
   /* for(int i=0;i<a.size();i++)
        printf("%d ",a[i]);*/
        int f;
        long long ans=0;
    for(int i=0;i<a.size();i++){
        f=n/a[i]-1;
        ans=0;
        ans=(long long)1*f*(f+1);
        ans=ans/2;
        ans=ans*(a[i]);
        ans+=(f+1);
        b.push_back(ans);
    }
   sort(b.begin(),b.end());
    for(int i=0;i<b.size();i++){
        printf("%lld ",b[i]);
    }
}