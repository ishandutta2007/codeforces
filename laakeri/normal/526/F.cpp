#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[303030];

int ma[303030];
int mi[303030];
int lol[606060];

ll v=0;

void getv(int l, int m, int r){
    ma[m]=a[m];
    mi[m]=a[m];
    for (int i=m-1;i>=l;i--){
        ma[i]=max(a[i], ma[i+1]);
        mi[i]=min(a[i], mi[i+1]);
    }
    ma[m+1]=a[m+1];
    mi[m+1]=a[m+1];
    for (int i=m+2;i<=r;i++){
        ma[i]=max(a[i], ma[i-1]);
        mi[i]=min(a[i], mi[i-1]);
    }
    //maksimi ja minimi vasemmalla
    for (int i=m;i>=l;i--){
        int le=ma[i]-mi[i];
        if (i+le>m&&i+le<=r){
            if (ma[i+le]<ma[i]&&mi[i+le]>mi[i]){
                v++;
            }
        }
    }
    //minimi vasemmalla maksimi oikealla
    int li=m+1;
    int ri=m+1;
    lol[ma[m+1]-(m+1)+303000]++;
    for (int i=m;i>=l;i--){
        while (li<=r&&ma[li]<=ma[i]){
            lol[ma[li]-li+303000]--;
            li++;
        }
        while (ri<r&&mi[ri+1]>mi[i]){
            ri++;
            lol[ma[ri]-ri+303000]++;
        }
        if (ri>=li){
            v+=(ll)lol[mi[i]-i+303000];
        }
    }
    for (int i=li;i<=r;i++){
        lol[ma[i]-i+303000]--;
    }
    for (int i=ri+1;i<=r;i++){
        lol[ma[i]-i+303000]++;
    }
}

void solve(int l, int r){
    if (l>=r) return;
    int m=(l+r)/2;
    getv(l, m, r);
    reverse(a+l, a+r+1);
    getv(l, m-(l+r+1)%2, r);
    reverse(a+l, a+r+1);
    solve(l, m);
    solve(m+1, r);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        a[x]=y;
    }
    solve(1, n);
    cout<<v+(ll)n<<endl;
}