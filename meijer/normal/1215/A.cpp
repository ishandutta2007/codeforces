#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define INF 1e9

const int MX=1e5;
int a[2], k[2], n;
int b[2];

int main() {
    cin>>a[0]>>a[1]>>k[0]>>k[1]>>n;
    if(k[1] < k[0]) swap(k[0], k[1]), swap(a[0], a[1]);
    int l = n-k[0]*a[0]-k[1]*a[1]+a[0]+a[1];
    b[0]=a[0], b[1]=a[1];
    int ans=0;
    while(l > 0) {
        if(b[1] == 0) b[0]--, l--, ans++;
        else          b[1]--, l--, ans++;
    }
    cout<<ans<<" ";
    ans=0; l = n;
    b[0]=a[0], b[1]=a[1];
    while(l > 0) {
        if(b[0] == 0) b[1]--, l-=k[1], ans++;
        else          b[0]--, l-=k[0], ans++;
    }
    if(l < 0) ans--;
    cout<<ans<<endl;
}