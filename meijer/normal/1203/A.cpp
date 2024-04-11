#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 1e9
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)

const int MX = 300;

int n, q;
int p[MX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>q;
    while(q--) {
        cin>>n;
        REP(i,0,n)cin>>p[i];
        bool pos=true;
        REP(i,0,n) {
            int j=i+1; j%=n;
            if(p[j] != (p[i]%n)+1) {
                pos=false;
                break;
            }
        }
        if(pos || n==1) {
            cout<<"YES"<<endl; continue;
        }
        pos = true;
        REP(i,0,n) {
            int j=i-1;
            if(j==-1) j=n-1;
            if(p[j] != (p[i]%n)+1) {
                pos=false;
                break;
            }
        }
        cout<<(pos?"YES":"NO")<<endl;
    }
}