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
	program();
}



//===================//
//   begin program   //
//===================//

const int MX='z'-'a'+1;
int t;
string p, h;
int cntP[MX], cntH[MX];

bool isCorrectString() {
	RE(i,MX)
		if(cntP[i] != cntH[i])
			return 0;
	return 1;
}

void program() {
	cin>>t;
	while(t--) {
		cin>>p>>h;
		RE(i,MX) cntP[i] = 0, cntH[i] = 0;
		for(char c:p) cntP[c-'a']++;
		if(h.size() < p.size()) {
			cout<<"NO"<<endl;
			continue;
		}
		RE(i,p.size()) cntH[h[i]-'a']++;
		bool pos=0;
		if(isCorrectString()) pos=1;
		RE(i,h.size()-p.size()) {
			cntH[h[i]-'a']--;
			cntH[h[i+p.size()]-'a']++;
			if(isCorrectString()) pos=1;
		}
		cout<<(pos?"YES":"NO")<<endl;
	}
}