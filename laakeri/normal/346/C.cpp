#include <iostream>
#include <set>

using namespace std;

const int N=1001010;
int st[2*N];

void setmin(int a, int b, int x){
    a+=N;
    b+=N;
    while (a<=b){
        if (a%2){
            if (st[a]==0||st[a]>x) st[a]=x;
            a++;
        }
        if (!(b%2)){
            if (st[b]==0||st[b]>x) st[b]=x;
            b--;
        }
        a/=2;
        b/=2;
    }
}

int getmin(int i){
    int mi=1e9;
    for (i+=N;i;i/=2){
        if (st[i]>0){
            mi=min(mi, st[i]);
        }
    }
    return mi;
}

int hds[1000010];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    set<int> xs;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        xs.insert(a);
    }
    int a,b;
    cin>>a>>b;
    if (a==b){
        cout<<0<<endl;
        return 0;
    }
    for (int x:xs){
        for (int i=(b/x)*x;i<=a;i+=x){
            if (i>=b){
                hds[i-b]=max(hds[i-b], x);
            }
        }
    }
    for (int i=0;i<a-b;i++){
        int mi;
        if (i) mi=getmin(i);
        else mi=0;
        int f=hds[i];
        if (f>0){
            setmin(i+1, min(i+f-1, (int)1e6+1), mi+1);
        }
        else{
            setmin(i+1, min(i+1, (int)1e6+1), mi+1);
        }
    }
    cout<<getmin(a-b)<<endl;
}