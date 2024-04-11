#include <iostream>

using namespace std;

typedef long long ll;

ll a[500001];
int N=500010;

int st[1010100];

void add(int i, int x){
    for (i+=N;i;i/=2) st[i]+=x;
}

int sum(int a, int b){
    if (b<a) return 0;
    int s=0;
    a+=N;
    b+=N;
    while (a<=b){
        if (a%2) s+=st[a++];
        if (!(b%2)) s+=st[b--];
        a/=2;
        b/=2;
    }
    return s;
}

int main(){
    ll s=0;
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>a[i];
        s+=a[i];
    }
    if ((s>=0&&s%3>0)||(s<0&&((-s)%3)>0)){
        cout<<0<<endl;
        return 0;
    }
    ll ss=s/3ll;
    s=0;
    for (int i=0;i<n;i++){
        s+=a[i];
        if (s==ss){
            add(i, 1);
        }
    }
    s=0;
    ll v=0;
    for (int i=n-1;i>=0;i--){
        s+=a[i];
        if (s==ss){
            v+=(ll)sum(0, i-2);
        }
    }
    cout<<v<<endl;
}