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
string li[]={
"H","HE",
"LI","BE","B","C","N","O","F","NE",
"NA","MG","AL","SI","P","S","CL","AR",
"K","CA","SC","TI","V","CR","MN","FE","CO","NI","CU","ZN","GA","GE","AS","SE","BR","KR",
"RB","SR","Y","ZR","NB","MO","TC","RU","RH","PD","AG","CD","IN","SN","SB","TE","I","XE",
"CS","BA","HF","TA","W","RE","OS","IR","PT","AU","HG","TL","PB","BI","PO","AT","RN",
"FR","RA","RF","DB","SG","BH","HS","MT","DS","RG","CN","NH","FL","MC","LV","TS","OG",
"LA","CE","PR","ND","PM","SM","EU","GD","TB","DY","HO","ER","TM","YB","LU",
"AC","TH","PA","U","NP","PU","AM","CM","BK","CF","ES","FM","MD","NO","LR"};

string s;
bool dp[12];

void program() {
    cin>>s;
    dp[s.size()] = 1;
    REV(i,0,s.size()) {
        dp[i] = 0;
        int l = s.size()-i;
        RE(j,118) {
            if(l < li[j].size()) continue;
            bool pos=1;
            RE(k,li[j].size()) {
                if(s[i+k] != li[j][k]) pos = 0;
            }
            if(pos) if(dp[i+li[j].size()]) dp[i] = 1;
        }
    }
    cout<<(dp[0]?"YES":"NO")<<endl;
}