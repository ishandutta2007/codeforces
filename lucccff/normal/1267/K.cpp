#include <bits/stdc++.h>
using namespace std;

int main(){
    long long i,j,k,l,m,n,t,s,ans;
    long long a[30],jie[30];
    j=1;
    for(i=1;i<=20;i++) {
        j*=i;
        jie[i]=j;
    }
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>k;
        l=2;
        while(k!=0) {
            a[l-2]=k%l;
            k/=l;
            l++;
        }
        l-=2;
        sort(a,a+l);
        s=1;
        k=1;
        for(j=l-1;j>=0;j--) {
            if (j!=l-1&&a[j]==a[j+1]) k++;
            else {
                s/=jie[k];
                k=1;
            }
            if (a[j]!=0)s*=j-a[j]+2;
            else s*=j-a[j]+1;
        }
        s/=jie[k];
        ans=s;
        if (a[0]!=0) {
            cout<<ans-1<<endl;
            continue;
        }
        s=1;
        k=1;
        for(j=l-1;j>=0&&a[j]!=0;j--) {
            if (j!=l-1&&a[j]==a[j+1]) k++;
            else {
                s/=jie[k];
                k=1;
            }
            s*=j-a[j]+1;
        }
        s/=jie[k];
        cout<<ans-s-1<<endl;;
    }
    return 0;
}