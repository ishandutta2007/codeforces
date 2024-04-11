#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second

const int MX=50;
int Q, n;
string bs[MX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>Q;
    while(Q--) {
        cin>>n;
        RE(i,n) cin>>bs[i];
        int white=0, black=0;
        RE(i,n)
            RE(j,bs[i].size())
                if(bs[i][j] == '1') white++;
                else black++;
        int even=0, uneven=0;
        RE(i,n)
            if(bs[i].size()%2 == 0) even++;
            else uneven++;
        if(white % 2 == 1 && black % 2 == 1) {
            if(uneven >= 2 && uneven % 2 == 0) {
                cout<<n<<endl;
            } else {
                cout<<max(0,n-1)<<endl;
            }
        } else
        if(white % 2 == 0 && black % 2 == 0) {
            if(uneven % 2 == 0) {
                cout<<n<<endl;
            } else {
                cout<<max(0,n-1)<<endl;
            }
        } else {
            if(uneven % 2 == 1) {
                cout<<n<<endl;
            } else {
                cout<<max(0,n-1)<<endl;
            }
        }
    }
}