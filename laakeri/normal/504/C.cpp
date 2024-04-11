#include <iostream>

using namespace std;

typedef long long ll;

int s[100001];

ll n;

int h[100001];
int ss[100001];

int test(int a, int b){
    for (int i=0;i<n;i++) ss[i]=s[i];
    for (int i=0;i<=n;i++) h[i]=0;
    for (int i=a;i<=b;i++){
        ss[i]=0;
        h[s[i]]++;
    }
    for (int i=a;i<min((int)n, b+1);i++){
        if (n-i-1<=b) break;
        if (h[s[n-i-1]]==0) return 0;
        else {
            h[s[n-i-1]]--;
            ss[i]=s[n-i-1];
        }
    }
    for (int i=b;i>=a;i--){
        if (n-i-1>=a) break;
        if (h[s[n-i-1]]==0) return 0;
        else{
            h[s[n-i-1]]--;
            ss[i]=s[n-i-1];
        }
    }
    for (int i=0;i<n;i++){
        if (ss[i]!=0&&ss[i]!=ss[n-i-1]){
            return 0;
        }
    }
    int of=0;
    for (int i=0;i<=n;i++){
        if (h[i]%2==1) of++;
    }
    if (of>1) return 0;
    if (of>0&&n%2==0) return 0;
    return 1;
}

int main(){
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>s[i];
    }
    ll l=0;
    for (;l<n/2;l++){
        if (s[l]!=s[n-l-1]) break;
    }
    ll v=0;
    if (l==n/2){
        cout<<((n+1)*n)/2<<endl;
        return 0;
    }
    if (test(l, n-l-1)){
        v+=l*l-1;
    }
    ll mi=l;
    ll ma=n-l-1;
    while (mi<=ma){
        int m=(mi+ma)/2;
        if (test(l, m)){
            ma=m-1;
        }
        else{
            mi=m+1;
        }
    }
    v+=(l+1)*(n-l-l-(mi-l));
    mi=l;
    ma=n-l-1;
    while (mi<=ma){
        int m=(mi+ma)/2;
        if (test(m, n-l-1)){
            mi=m+1;
        }
        else{
            ma=m-1;
        }
    }
    v+=(l+1)*(ma-l+1);
    cout<<v<<endl;
}