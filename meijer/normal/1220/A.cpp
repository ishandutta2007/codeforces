#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define INF 1e9

const int MX=1e5;
int n;
string s;

int main() {
    cin>>n;
    cin>>s;
    int zeros=0, ones=0;
    REP(i,0,n)
        zeros += s[i]=='z', ones += s[i]=='n';
    if(ones == 0) cout<<0;
    else cout<<1;
    REP(i,1,ones)
        cout<<" "<<1;
    REP(i,ones==0,zeros)
        cout<<" "<<0;
    cout<<endl;
}