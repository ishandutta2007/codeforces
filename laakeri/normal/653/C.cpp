#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

int fl[202020];
int a[202020];

int fail=0;

void check(int i){
    int f=0;
    if (a[i-1]>=a[i]||a[i+1]>=a[i]){
        f=1;
    }
    fail+=f-fl[i];
    fl[i]=f;
}

int n;

int test(int l, int r){
    if (l<0||l>=n||r<0||r>=n) return 0;
    swap(a[l], a[r]);
    for (int i=l-1;i<=l+1;i++){
        if (i%2==1&&i>=0&&i<n){
            check(i);
        }
    }
    for (int i=r-1;i<=r+1;i++){
        if (i%2==1&&i>=0&&i<n){
            check(i);
        }
    }
    int re=0;
    if (fail==0) re=1;
    swap(a[l], a[r]);
    for (int i=l-1;i<=l+1;i++){
        if (i%2==1&&i>=0&&i<n){
            check(i);
        }
    }
    for (int i=r-1;i<=r+1;i++){
        if (i%2==1&&i>=0&&i<n){
            check(i);
        }
    }
    return re;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    for (int i=1;i<n;i+=2){
        check(i);
    }
    int f=1;
    for (int i=1;i<n;i+=2){
        if (fl[i]){
            f=i;
            break;
        }
    }
    set<pair<int, int> > fo;
    for (int i=0;i<n;i++){
        if (test(i, f-1)){
            fo.insert({min(i, f-1), max(i, f-1)});
        }
        if (test(i, f)){
            fo.insert({min(i, f), max(i, f)});
        }
        if (test(i, f+1)){
            fo.insert({min(i, f+1), max(i, f+1)});
        }
    }
    cout<<fo.size()<<endl;
}