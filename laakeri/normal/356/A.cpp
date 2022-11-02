#include <iostream>

using namespace std;

const int N=303030;
int st[2*N];
int w[300001];

void setmin(int a, int b, int x){
    a+=N;
    b+=N;
    while (a<=b){
        if (a%2){
            if (st[a]==0||st[a]>x){
                st[a]=x;
            }
            a++;
        }
        if (!(b%2)){
            if (st[b]==0||st[b]>x){
                st[b]=x;
            }
            b--;
        }
        a/=2;
        b/=2;
    }
}

int getmin(int i){
    int mi=9999999;
    for (i+=N;i;i/=2){
        if (st[i]>0){
            mi=min(st[i], mi);
        }
    }
    return mi;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=m;i++){
        int l,r,x;
        cin>>l>>r>>x;
        w[i]=x;
        setmin(l, x-1, i);
        setmin(x+1, r, i);
    }
    for (int i=1;i<=n;i++){
        int mm=getmin(i);
        if (mm==9999999||mm==0){
            cout<<0<<" ";
        }
        else{
            cout<<w[mm]<<" ";
        }
    }
}