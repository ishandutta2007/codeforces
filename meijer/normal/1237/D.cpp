#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second

const int MX=4e5;
ll n, a[MX], N;
ll segMax[MX*4], segMin[MX*4];
ll ans[MX];

void buildSeg(int p=0, int l=0, int r=N-1) {
    if(l == r) {
        segMax[p]=segMin[p]=a[l];
    } else {
        int m=(l+r)/2;
        buildSeg(p*2+1,l,m);
        buildSeg(p*2+2,m+1,r);
        segMax[p]=max(segMax[p*2+1],segMax[p*2+2]);
        segMin[p]=min(segMin[p*2+1],segMin[p*2+2]);
    }
}
int getMax(int i, int j, int p=0, int l=0, int r=N-1) {
    if(j < l || i > r)
        return 0;
    if(i <= l && j >= r)
        return segMax[p];
    int m=(l+r)/2;
    int a=getMax(i,j,p*2+1,l,m);
    int b=getMax(i,j,p*2+2,m+1,r);
    return max(a,b);
}
int getMin(int i, int j, int p=0, int l=0, int r=N-1) {
    if(j < l || i > r)
        return INF;
    if(i <= l && j >= r)
        return segMin[p];
    int m=(l+r)/2;
    int a=getMin(i,j,p*2+1,l,m);
    int b=getMin(i,j,p*2+2,m+1,r);
    return min(a,b);
}
int getFirstBigger(int i) {
    int v=a[i];
    int lb=i+1, ub=N-1;
    while(lb != ub) {
        int mid=(lb+ub)/2;
        if(getMax(i,mid) > v) ub = mid;
        else                  lb = mid+1;
    }
    return lb;
}
int getFirstSmaller(int i) {
    int v=(a[i]+1)/2;
    int lb=i+1, ub=N-1;
    while(lb != ub) {
        int mid=(lb+ub)/2;
        if(getMin(i,mid) < v) ub = mid;
        else                  lb = mid+1;
    }
    return lb;
}
ll getAns(int i) {
    if(ans[i] == -1) {
        int j = getFirstBigger(i);
        int k = getFirstSmaller(i);
        if(k < j) {
            ans[i] = k-i;
        } else {
            ans[i] = j-i+getAns(j);
        }
    }
    return ans[i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n; N=n*3;
    RE(i,n) cin>>a[i];
    RE(i,n) a[i+n]=a[i+n+n]=a[i];
    ll mx=0;
    RE(i,n) mx=max(mx, a[i]);
    bool foundBreak=0;
    RE(i,n) if(a[i] < (mx+1)/2) foundBreak = 1;
    if(!foundBreak) {
        RE(i,n) cout<<(i==0?"":" ")<<-1; cout<<endl;
    } else {
        //normal solution
        RE(i,N)
            ans[i] = -1;
        buildSeg();
        RE(i,n)
            cout<<(i==0?"":" ")<<getAns(i); cout<<endl;
    }
}