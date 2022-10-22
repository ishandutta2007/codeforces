#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define INF 1e9

string s;
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s; n=s.size();
    char smallest='z'+1;
    REP(i,0,n) {
        cout<<(s[i]>smallest?"Ann":"Mike")<<endl;
        smallest = min(smallest, s[i]);
    }
}