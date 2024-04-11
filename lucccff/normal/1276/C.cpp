#include <bits/stdc++.h>
using namespace std;

int main(){
    std::ios::sync_with_stdio(false);
    long long i,j,k,l,m,n,t,s,max;
    long long a[400010],b[400010],d[10000],ans[400010];
    pair <int,int> c[400010];
    map <int,int> p;
    cin>>n;
    m=0;
    for(i=0;i<n;i++) {
        cin>>a[i];
        if (!p.count(a[i])) {
            p[a[i]]=1;
            b[m++]=a[i];
        }
        else {
            p[a[i]]=p[a[i]]+1;
        }
    }
    for(i=0;i<m;i++) {
        c[i]=make_pair(p[b[i]],b[i]);
    }
    sort(c,c+m);
    l=sqrt(n);
    k=0;
    d[l+1]=0;
    for(i=l;i>=1;i--) {
        d[i]=d[i+1]+k;
        while(k<n&&c[m-k-1].first>i) {
            d[i]+=c[m-k-1].first-i;
            k++;
        }
    }
    max=0;
    t=0;
    s=0;
    for(i=l;i>=1;i--) {
        j=(n-d[i])/i;
        if (j>=i) {
            if (max<j*i) {
                max=j*i;
                t=i;
                s=j;
            }
        }
    }
    j=0;
    for(i=m-1;i>=0;i--) {
        if (c[i].first>t) {
            j+=c[i].first-t;
            c[i].first=t;
        }
    }
    i=0;
    while (j+max<n) {
        if (c[i].first<n-j-max) {
            j+=c[i].first;
            c[i].first=0;
        }
        else {
            c[i].first-=n-j-max;
            j=n-max;
        }
        i++;
    }
    sort(c,c+m);
    k=m-1;
    for(i=0;i<s;i++) {
        for(j=0;j<t;j++) {
            while(k>0&&c[k].first==0) {
                k--;
            }
            ans[(i+j)%s+j*s]=c[k].second;
            c[k].first--;
        }
    }
    cout<<max<<endl;
    cout<<t<<' '<<s<<endl;
    for(i=0;i<t;i++) {
        for(j=0;j<s;j++) {
            cout<<ans[i*s+j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}