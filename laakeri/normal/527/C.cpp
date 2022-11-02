#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#define F first
#define S second
using namespace std;
typedef long long ll;

const int N=1<<19;
int st1[2*N];
int st2[2*N];
int st3[2*N];
int st4[2*N];

void add(int*st, int i, int x){
    for (i+=N;i;i/=2){
        st[i]+=x;
    }
}
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
int kth(int*st, int i, int k){
    if (i>=N) return i-N;
    if (st[i*2]>=k){
        return kth(st, i*2, k);
    }
    return kth(st, i*2+1, k-st[i*2]);
}
int lower(int*st, int x){
    int s=sum(st, 0, x);
    return kth(st, 1, s);
}
int upper(int*st, int x){
    int s=sum(st, 0, x);
    return kth(st, 1, s+1);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int w,h,n;
    cin>>w>>h>>n;
    add(st1, 0, 1);
    add(st1, h, 1);
    add(st2, 0, 1);
    add(st2, w, 1);
    add(st3, h, 1);
    add(st4, w, 1);
    for (int i=0;i<n;i++){
        char t;
        int x;
        cin>>t>>x;
        if (t=='H'){
            int hi=upper(st1, x);
            int lo=lower(st1, x);
            int v=hi-lo;
            add(st3, v, -1);
            add(st1, x, 1);
            add(st3, hi-x, 1);
            add(st3, x-lo, 1);
        }
        else{
            int hi=upper(st2, x);
            int lo=lower(st2, x);
            int v=hi-lo;
            add(st4, v, -1);
            add(st2, x, 1);
            add(st4, hi-x, 1);
            add(st4, x-lo, 1);
        }
        int a=sum(st3, 0, 300000);
        int b=sum(st4, 0, 300000);
        cout<<(ll)((ll)kth(st3, 1, a))*((ll)kth(st4, 1, b))<<'\n';
    }
}