#include <bits/stdc++.h>
using namespace std;

typedef pair <int,int> qi;
qi a[200010];
int b[2000010][20],t[20],n;

map <int,int> p;

int sou(int i,int h,int k) {
    if (t[h]==1) return i;
    if (i+t[h+1]<n) {
        if (k>b[i][h+1]) {
            return sou(i+t[h+1],h+1,k-b[i][h+1]);
        }
        else {
            return sou(i,h+1,k);
        }
    }
    else {
        return sou(i,h+1,k);
    }
}

void clear(int i,int h,int j) {
    b[j][h]--;
    if (t[h]==1) return;
    else if (j+t[h+1]<=i) {
        clear(i,h+1,j+t[h+1]);
    }
    else {
        clear(i,h+1,j);
    }
}

int main(){
    int i,j,k,l,m;
    qi c[200010];
    int ans[200010],d[200010],e[200010];
    cin>>n;
    for(i=0;i<n;i++) {
        cin>>l;
        e[i]=l;
        a[i].first=l;
        a[i].second=n-i;
    }
    sort(a,a+n);

    b[0][0]=n;
    int x=1;
    while(x<n) x<<=1;
    t[0]=x;
    l=0;
    for(x>>=1;x>=1;x>>=1) {
        l++;
        t[l]=x;
        for(i=0;i<n;i+=x) {
            if (i+x<n) b[i][l]=x;
            else b[i][l]=n-i;
        }
    }

    cin>>m;
    for(i=0;i<m;i++) {
        cin>>l>>d[i];
        c[i].first=l;
        c[i].second=i;
    }
    sort(c,c+m);
    
    l=m-1;
    for(i=n;i>0;i--) {
        while(l>=0&&c[l].first==i) {
            ans[c[l].second]=e[sou(0,0,d[c[l].second])];
            l--;
        }
        clear(n-a[n-i].second,0,0);
    }

    for(i=0;i<m;i++) {
        cout<<ans[i]<<endl;
    }
    return 0;
}