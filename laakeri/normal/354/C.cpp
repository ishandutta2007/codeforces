#include <iostream>

using namespace std;

const int N=2020202;
int st[N*2];

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

int main(){
    int n,k;
    cin>>n>>k;
    int mia=99999999;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        st[N+a]++;
        mia=min(a, mia);
    }
    for (int i=N-1;i;i--){
        st[i]=st[i*2]+st[i*2+1];
    }
    int br=min(mia, k);
    for (int i=k+1;i<=mia;i++){
        int su=0;
        for (int ii=i;ii<=1e6;ii+=i){
            su+=sum(ii, min(ii+k, (int)1e6));
        }
        if (su==n){
            br=i;
        }
    }
    cout<<br<<endl;
}