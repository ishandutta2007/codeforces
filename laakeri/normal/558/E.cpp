#include <bits/stdc++.h>
using namespace std;

const int N=1<<17;
int st[2*N][30];
int lazy[2*N][30];

void golazy(int i, int k, int sz){
    if (lazy[i][k]>0&&i<N){
        lazy[i*2][k]=lazy[i][k];
        lazy[i*2+1][k]=lazy[i][k];
        if (lazy[i][k]==1){
            st[i*2][k]=0;
            st[i*2+1][k]=0;
        }
        else{
            st[i*2][k]=sz/2;
            st[i*2+1][k]=sz/2;
        }
        lazy[i][k]=0;
    }
}

void push(int i, int k, int sz){
    if (i>1) push(i/2, k, sz*2);
    golazy(i, k, sz);
}

int sum(int a, int b, int k){
    a+=N;
    b+=N;
    push(a, k, 1);
    push(b, k, 1);
    int s=0;
    while (a<=b){
        if (a%2) s+=st[a++][k];
        if (!(b%2)) s+=st[b--][k];
        a/=2;
        b/=2;
    }
    return s;
}

void setv(int i, int k, int stl, int str, int l, int r, int v){
    if (stl>r||str<l) return;
    golazy(i, k, str-stl+1);
    if (l<=stl&&str<=r){
        //cout<<"set "<<k<<" "<<stl<<" "<<str<<" "<<(str-stl+1)<<" "<<v<<endl;
        st[i][k]=v*(str-stl+1);
        lazy[i][k]=v+1;
    }
    else{
        int m=(stl+str)/2;
        setv(i*2, k, stl, m, l, r, v);
        setv(i*2+1, k, m+1, str, l, r, v);
        st[i][k]=st[i*2][k]+st[i*2+1][k];
    }
}

void sv(int a, int b, int k, int v){
    setv(1, k, 0, N-1, a, b, v);
}

int n;

void pr(){
    for (int i=0;i<n;i++){
        for (int c=0;c<30;c++){
            if (sum(i, i, c)==1){
                cout<<(char)(c+'a');
                break;
            }
        }
    }
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin>>n>>q;
    string s;
    cin>>s;
    for (int i=0;i<n;i++){
        setv(1, s[i]-'a', 0, N-1, i, i, 1);
    }
    for (int i=0;i<q;i++){
        int a,b,k;
        cin>>a>>b>>k;
        a--;
        b--;
        int f=0;
        if (k==1){
            for (int c=0;c<30;c++){
                int t=sum(a, b, c);
                if (t>0){
                    sv(a, b, c, 0);
                    sv(a+f, a+t-1+f, c, 1);
                    f+=t;
                }
            }
        }
        else{
            for (int c=29;c>=0;c--){
                int t=sum(a, b, c);
                if (t>0){
                    sv(a, b, c, 0);
                    sv(a+f, a+t-1+f, c, 1);
                    f+=t;
                }
            }
        }
    }
    pr();
}