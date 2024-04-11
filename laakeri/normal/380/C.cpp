#include <iostream>

using namespace std;

struct b{
    int v=0;
    int l=0;
    int r=0;
};
const int N=1<<20;
b st[2*N];
b mer(b l, b r){
    b re;
    re.v=l.v+r.v+min(l.l, r.r);
    re.l=l.l+r.l-min(l.l, r.r);
    re.r=l.r+r.r-min(l.l, r.r);
    return re;
}
void init(int i){
    if (i>=N) return;
    init(i*2);
    init(i*2+1);
    st[i]=mer(st[i*2], st[i*2+1]);
}

b get(int i, int stl, int str, int l, int r){
    if (l>str||r<stl) return b();
    if (l<=stl&&str<=r){
        return st[i];
    }
    else{
        int m=(stl+str)/2;
        return mer(get(i*2, stl, m, l, r), get(i*2+1, m+1, str, l, r));
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    int n=s.size();
    int q;
    cin>>q;
    for (int i=0;i<n;i++){
        if (s[i]=='(') st[i+N].l=1;
        if (s[i]==')') st[i+N].r=1;
    }
    init(1);
    for (int i=0;i<q;i++){
        int a, b;
        cin>>a>>b;
        cout<<get(1, 0, N-1, a-1, b-1).v*2<<'\n';
    }
}