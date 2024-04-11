#include <bits/stdc++.h>
using namespace std;
struct num{
    int len;
    char s[101010];
    bool operator < (const num &a)const{
        if(len != a.len) return len<a.len;

        for(int i=len;i>=1;i--) if(s[i] != a.s[i]) return s[i] < a.s[i];

        return 0;
    }
}n1,n2;
int n;
char N[101010];
void f(num *a,int l,int r){
    int fl=0;
    for(int i=0;l-i>0 || r-i>l;i++){
        if(l-i<=0){
            (*a).s[++(*a).len] = N[r-i]+fl;
        }else if(r-i<=l){
            (*a).s[++(*a).len] = N[l-i]+fl;
        }else{
            (*a).s[++(*a).len] = N[r-i]+N[l-i]+fl-'0';
        }

        if((*a).s[(*a).len] > '9'){
            (*a).s[(*a).len]-=10;
            fl=1;
        }else fl=0;
    }
    if(fl) (*a).s[++(*a).len]='1';
}
void out(num a){
    for(int i=a.len;i>=1;i--) printf("%c",a.s[i]);
}
int main(){
    scanf("%d %s",&n,N+1);
    if(n%2){
        for(int i=0;i<n/2;i++){
            if(N[n/2-i+1]!='0' && N[n/2+i+2]!='0'){
                f(&n1,n/2-i,n);
                f(&n2,n/2+i+1,n);
                out(min(n1,n2));
                return 0;
            }else if(N[n/2-i+1]!='0'){
                f(&n1,n/2-i,n);
                out(n1);
                return 0;
            }else if(N[n/2+i+2]!='0'){
                f(&n1,n/2+i+1,n);
                out(n1);
                return 0;
            }
        }
    }else{
        for(int i=0;i<n/2;i++){
            if(N[n/2-i+1]!='0' && N[n/2+i+1]!='0'){
                f(&n1,n/2-i,n);
                f(&n2,n/2+i,n);
                out(min(n1,n2));
                return 0;
            }else if(N[n/2-i+1]!='0'){
                f(&n1,n/2-i,n);
                out(n1);
                return 0;
            }else if(N[n/2+i+1]!='0'){
                f(&n1,n/2+i,n);
                out(n1);
                return 0;
            }
        }
    }
}