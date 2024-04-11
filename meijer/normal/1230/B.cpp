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

const int MX=1e5;
string s;
int n, k;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k>>s;
    k = min(k, n);
    if(n==1 && k==1) s[0]='0', k=0;
    int i=0;
    while(k > 0 && i<n) {
        if(i == 0) {
            if(s[i] != '1')
                s[i] = '1', k--;
        } else {
            if(s[i] != '0')
                s[i] = '0', k--;
        }
        i++;
    }
    cout<<s<<endl;
}