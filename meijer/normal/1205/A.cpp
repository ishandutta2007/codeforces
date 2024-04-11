#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define REP(a,b,c) for(int a=int(b); a!=int(c); a++)

int N;

int main() {
    cin >> N;
    if(N % 2 == 0) {
        cout<<"NO"<<endl;
    } else {
        cout<<"YES"<<endl;
        cout<<"1";
        bool high=true;
        REP(i,1,N) {
            int a = (i+1)*2 - 1;
            cout<<" "<<(high?a+1:a);
            high = !high;
        }
        REP(i,0,N) {
            int a = (i+1)*2 - 1;
            cout<<" "<<(high?a+1:a);
            high = !high;
        }
        cout<<endl;
    }
}