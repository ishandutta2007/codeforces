#include <iostream>

using namespace std;

const int N=1<<18;

int st1[2*N];
int st2[2*N];
int st3[2*N];

int sum(int*st, int a, int b){
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
void add(int*st, int i, int v){
    for (i+=N;i;i/=2){
        st[i]+=v;
    }
}
int kth(int*st, int i, int k){
    if (i>=N) return i-N;
    if (st[i*2]>=k) return kth(st, i*2, k);
    else return kth(st, i*2+1, k-st[i*2]);
}

int a[200001];
int b[200001];

int h[200001];
int n;
void addd(int i, int v){
    h[i]+=v;
    if (h[i]>=n-i){
        if (i){
            addd(i-1, h[i]/(n-i));
        }
        h[i]%=n-i;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for (int i=0;i<n;i++){
        add(st1, i, 1);
        add(st2, i, 1);
        add(st3, i, 1);
    }
    for (int i=0;i<n;i++) cin>>a[i];
    for (int i=0;i<n;i++) cin>>b[i];
    for (int i=0;i<n;i++){
        int lol=sum(st1, 0, a[i]-1)+sum(st2, 0, b[i]-1);
        addd(i, lol);
        add(st1, a[i], -1);
        add(st2, b[i], -1);
    }
    for (int i=0;i<n;i++){
        int asd=kth(st3, 1, h[i]+1);
        add(st3, asd, -1);
        cout<<asd<<" ";
    }
}