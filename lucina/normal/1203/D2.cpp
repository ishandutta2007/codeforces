#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,m,pre[maxn],suf[maxn];
string s,t;
///t is subsequence of s;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
   cin>>s>>t;
   n=(int)s.length();m=(int)t.length();
   int pt=0;
   for(int i=0;i<n;i++){
        if(s[i]==t[pt]){
            pre[pt]=i;
            pt++;
        }
        if(pt>=m)break;
   }
    pt=m-1;
   for(int i=n-1;i>=0;i--){
    if(s[i]==t[pt]){
        suf[pt]=i;
        pt--;
    }
    if(pt<0)break;
   }
   int ans=0;
   for(int i=0;i<=m;i++){
        ///take first i elements of m
        if(i==0){
            int cur=suf[0];
            ans=max(ans,cur);
            continue;
        }
        int l=pre[i-1];
        ///rest m-i element

        int r=(i==m)?n:suf[i];
        ans=max(ans,r-l-1);
   }
   printf("%d\n",ans);
}