#include <iostream>
#include <vector>
#define F first
#define S second

using namespace std;

typedef long long ll;

const int N=101010;
ll mast[2*N];
ll mist[2*N];
ll mist2[2*N];
int mist2f[2*N];

ll inff=1e9;

ll getmax(int a, int b){
    a+=N;
    b+=N;
    ll ma=-inff;
    while (a<=b){
        if (a%2) ma=max(ma, mast[a++]);
        if (!(b%2)) ma=max(ma, mast[b--]);
        a/=2;
        b/=2;
    }
    return ma;
}

pair<ll, int> getmin2(int a, int b){
    if (a<0||b<0) return {0, -1};
    a+=N;
    b+=N;
    ll mi=inff;
    int f=0;
    while (a<=b){
        if (a%2) {
            if (mist2[a]<=mi) f=mist2f[a];
            mi=min(mi, mist2[a++]);
        }
        if (!(b%2)) {
            if (mist2[b]<=mi) f=mist2f[b];
            mi=min(mi, mist2[b--]);
        }
        a/=2;
        b/=2;
    }
    return {mi, f};
}

ll getmin(int a, int b){
    a+=N;
    b+=N;
    ll mi=inff;
    while (a<=b){
        if (a%2) mi=min(mi, mist[a++]);
        if (!(b%2)) mi=min(mi, mist[b--]);
        a/=2;
        b/=2;
    }
    return mi;
}

int setmax(int i, ll x){
    for (i+=N;i;i/=2){
        mast[i]=max(mast[i], x);
    }
}

int setmin2(int i, ll x, int ii){
    for (i+=N;i;i/=2){
        if (x<=mist2[i]) mist2f[i]=ii;
        mist2[i]=min(mist2[i], x);
    }
}

int setmin(int i, ll x){
    for (i+=N;i;i/=2){
        mist[i]=min(mist[i], x);
    }
}

ll a[100001];

int from[100001];

int main(){
    for (int i=0;i<2*N;i++){
        mast[i]=-inff;
        mist2[i]=inff;
        mist[i]=inff;
    }
    int n,l;
    ll s;
    cin>>n>>s>>l;
    int lol=0;
    int v=0;
    for (int i=0;i<n;i++){
        cin>>a[i];
        setmax(i, a[i]);
        setmin(i, a[i]);
        while (lol<i&&(getmax(lol, i)>a[i]+s||getmin(lol, i)<a[i]-s)){
            lol++;
        }
        //cout<<i<<" "<<lol-1<<" "<<i-l<<" "<<getmin2(lol-1, i-l).F+1<<" "<<getmin2(lol-1, i-l).S<<endl;
        if (i==n-1){
            from[i]=getmin2(lol-1, i-l).S;
            v=getmin2(lol-1, i-l).F+1;
        }
        else{
            from[i]=getmin2(lol-1, i-l).S;
            setmin2(i, getmin2(lol-1, i-l).F+1, i);
        }
    }
    vector<int> lols;
    int x=n-1;
    while (x>=0){
        lols.push_back(x);
        x=from[x];
    }
    int ss=0;
    if (lols.size()!=v) {
        cout<<-1<<endl;
        return 0;
    }
    for (int i=lols.size()-1;i>=0;i--){
        if (lols[i]-ss+1<l) {
            cout<<-1<<endl;
            return 0;
        }
        if (getmax(ss, lols[i])-getmin(ss, lols[i])>s){
            cout<<-1<<endl;
            return 0;
        }
        ss=lols[i]+1;
    }
    cout<<v<<endl;
}