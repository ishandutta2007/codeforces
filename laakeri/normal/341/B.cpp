#include <iostream>

using namespace std;

const int N=101010;
int st[2*N];

int add(int i, int x){
    st[i+N]=x;
    for (i=(i+N)/2;i;i/=2){
        st[i]=max(st[i*2], st[i*2+1]);
    }
}

int getmax(int a, int b){
    a+=N;
    b+=N;
    int ma=0;
    while (a<=b){
        if (a%2) ma=max(ma, st[a++]);
        if (!(b%2)) ma=max(ma, st[b--]);
        a/=2;
        b/=2;
    }
    return ma;
}

int main(){
    int n;
    cin>>n;
    int m=0;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        int v=getmax(1, a);
        v++;
        m=max(m, v);
        add(a, v);
    }
    cout<<m<<endl;
}