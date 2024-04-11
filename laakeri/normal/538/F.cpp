#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

const int N=1<<18;
int st[2*N];

void add(int i, int x){
    for (i+=N;i;i/=2){
        st[i]+=x;
    }
}

int sum(int a, int b){
    a+=N;
    b+=N;
    int s=0;
    while (a<=b){
        if (a%2) s+=st[a++];
        if (!(b%2)) s+=st[b--];
        a/=2;
        b/=2;
    }
    return s;
}

int a[202020];
int v[202020];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<pair<int, int> > ps;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        ps.push_back({a[i], i});
    }
    sort(ps.begin(), ps.end());
    int i2=0;
    for (int i=0;i<(int)ps.size();i++){
        while (i2<i&&ps[i2].F<ps[i].F){
            add(ps[i2].S, 1);
            i2++;
        }
        for (int k=1;k*(ps[i].S-1)+2<=n&&k<n;k++){
            v[k]+=sum(k*(ps[i].S-1)+2, min(k*ps[i].S+1,n));
        }
    }
    for (int k=1;k<n;k++){
        cout<<v[k]<<" ";
    }
}