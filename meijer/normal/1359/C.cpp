#include <bits/stdc++.h>
using namespace std;

//macros
typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define RE1(a,c) REP(a,1,c+1)
#define REI(a,b,c) REP(a,b,c+1)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second
#define sz size()
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//===================//
//  Added libraries  //
//===================//

//===================//
//end added libraries//
//===================//

void program();
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    program();
}


//===================//
//   begin program   //
//===================//

const int MX = 5e5;
int testCases;
double h, c, t;

double getTemp(double i) {
    double tot=(i*2.0+1.0);
    return ((i+1.0)*h + i*c)/tot;
}

void program() {
    cin>>testCases;
    while(testCases--) {
        cin>>h>>c>>t;
        double mn = (h+c)/2.0;
        double mx = h;
        if(t >= mx) {
            cout<<1<<endl;
            continue;
        }
        if(t <= mn) {
            cout<<2<<endl;
            continue;
        }
        int lb=0, ub=1e7;
        while(lb != ub) {
            int mid=(lb+ub+1)/2;
            double temp=getTemp(mid);
            if(temp > t) lb = mid;
            else ub = mid-1;
        }
        double temp1 = getTemp(lb);
        double temp2 = getTemp(lb+1);
        if(abs(temp2-t) < abs(temp1-t)) lb++;
        cout<<lb*2+1<<endl;
    }
}