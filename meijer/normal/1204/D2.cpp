#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define INF 1e9

const int MX=3000;
stack<int> k;
string s, t;
int n=0;

int main() {
    cin>>s; n=s.size();
    t.assign(n, '0');
    REP(i,0,n) {
        if(s[i] == '1') k.push(i);
        else {
            if(k.empty()) continue;
            t[k.top()] = '1'; k.pop();
        }
    }
    cout<<t<<endl;
}