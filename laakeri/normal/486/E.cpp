#include <iostream>

using namespace std;

int a[100001];

const int N=101010;

int sq[100001];

int mast[2*N];

int bl[101010];
int ism[100001];

int getmax(int a, int b){
    a+=N;
    b+=N;
    int m=0;
    while (a<=b){
        if (a%2) m=max(m, mast[a++]);
        if (!(b%2)) m=max(m, mast[b--]);
        a/=2;
        b/=2;
    }
    return m;
}

void setmax(int i, int x){
    for (i+=N;i;i/=2){
        mast[i]=max(mast[i], x);
    }
}

int maxx[100001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    int msq=0;
    for (int i=0;i<n;i++){
        int ms=getmax(0, a[i]-1)+1;
        sq[i]=ms;
        msq=max(ms, msq);
        setmax(a[i], ms);
    }
    for (int i=n-1;i>=0;i--){
        if (sq[i]==msq||maxx[sq[i]+1]>a[i]){
            ism[i]=1;
            bl[sq[i]]++;
            maxx[sq[i]]=max(a[i], maxx[sq[i]]);
        }
    }
    for (int i=0;i<n;i++){
        if (!ism[i]){
            cout<<1;
        }
        else{
            if (bl[sq[i]]>1){
                cout<<2;
            }
            else{
                cout<<3;
            }
        }
    }
}