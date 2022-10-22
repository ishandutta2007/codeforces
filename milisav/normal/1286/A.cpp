#include<bits/stdc++.h>
using namespace std;
int n;
int a[1000];
bool ap[1000];
vector<int> b[2];
vector<int> c[2];
int main() {
    scanf("%d",&n);
    int ans=0;
    for(int i=0;i<n;i++) {
        scanf("%d",&a[i]);
        if(i>0 && a[i]!=0 && a[i-1]!=0) {
            if(a[i]%2!=a[i-1]%2) ans++;
        }
        ap[a[i]]=true;
    }
    if(n==1) {
        printf("0");
        return 0;
    }
    int x=0,y=0;
    for(int i=1;i<=n;i++) {
        if(!ap[i]) {
            if(i%2==0) x++;
            else y++;
        }
    }
    if(x+y==n) {
        printf("1");
        return 0;
    }
    int p=0;
    int q=n-1;
    if(a[0]==0) {
        while(a[p]==0) p++;
        c[a[p]%2].push_back(p);
    }
    if(a[n-1]==0) {
        while(a[q]==0) q--;
        c[a[q]%2].push_back(n-1-q);
    }
    for(int i=p;i<=q;i++) {
        if(a[i]==0) {
            int j=i-1;
            while(a[i]==0) i++;
            if(a[j]%2==a[i]%2) b[a[i]%2].push_back(i-j-1);
            else ans++;
        }
    }
    ans+=(2*b[0].size()+2*b[1].size()+c[0].size()+c[1].size());
    sort(b[0].begin(),b[0].end());
    sort(b[1].begin(),b[1].end());
    sort(c[0].begin(),c[0].end());
    sort(c[1].begin(),c[1].end());
    for(int i=0;i<b[0].size();i++) {
        if(x>=b[0][i]) {
            x-=b[0][i];
            ans-=2;
        }
    }
    for(int i=0;i<b[1].size();i++) {
        if(y>=b[1][i]) {
            y-=b[1][i];
            ans-=2;
        }
    }
    for(int i=0;i<c[0].size();i++) {
        if(x>=c[0][i]) {
            x-=c[0][i];
            ans--;
        }
    }
    for(int i=0;i<c[1].size();i++) {
        if(y>=c[1][i]) {
            y-=c[1][i];
            ans--;
        }
    }
    printf("%d",ans);
    return 0;
}