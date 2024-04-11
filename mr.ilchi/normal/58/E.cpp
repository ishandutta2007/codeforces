/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <complex>
#include <stack>
#include <deque>
#include <queue>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<double> point;
typedef long double ldb;

int lena,lenb,lenc;
int dp[25][25][25][25][2][2];
string s,a,b,c,A,B,C;

int go (int pos, int pa, int pb, int pc, int key, int sh){
	int &ret = dp[pos][pa][pb][pc][key][sh];
	if (ret!=-1)
		return ret;
	if (pa==(int)a.size() && pb==(int)b.size() && pc==(int)c.size() && key==0)
		return ret=true;
	ret = false;
	for (int i=0; i<10; i++) if (i==0 || pos<lena){
		for (int j=0; j<10; j++) if (j==0 || pos<lenb){
			int k = (i+j+key)%10;
			if (k!=0 && pos>=lenc)
				continue;
			bool f1= (pa<(int)a.size() && a[pa]-'0' == i);
			bool f2= (pb<(int)b.size() && b[pb]-'0' == j);
			bool f3= (pc<(int)c.size() && c[pc]-'0' == k);
			if (sh & !f1 && !f2 && !f3)
				continue;
			if (go(pos+1,pa+f1,pb+f2,pc+f3,(i+j+key)>9,!f1 && !f2 && !f3))
				return ret=true;
		}
	}
	return ret = false;
}

void print (int pos, int pa, int pb, int pc, int key, int sh){
	int &ret = dp[pos][pa][pb][pc][key][sh];
	if (pa==(int)a.size() && pb==(int)b.size() && pc==(int)c.size() && key==0)
		return;
	ret = false;
	for (int i=0; i<10; i++) if (i==0 || pos<lena){
		for (int j=0; j<10; j++) if (j==0 || pos<lenb){
			int k = (i+j+key)%10;
			if (k!=0 && pos>=lenc)
				continue;
			bool f1= (pa<(int)a.size() && a[pa]-'0' == i);
			bool f2= (pb<(int)b.size() && b[pb]-'0' == j);
			bool f3= (pc<(int)c.size() && c[pc]-'0' == k);
			if (sh & !f1 && !f2 && !f3)
				continue;
			if (go(pos+1,pa+f1,pb+f2,pc+f3,(i+j+key)>9,!f1 && !f2 && !f3)){
				if (pos<lena) A = char(i+'0') + A;
				if (pos<lenb) B = char(j+'0') + B;
				if (pos<lenc) C = char(k+'0') + C;
				print(pos+1,pa+f1,pb+f2,pc+f3,(i+j+key)>9,!f1 && !f2 && !f3);
				return;
			}
		}
	}
}

int main(){
	cin >> s;
	for (int i=0; i<(int)s.size(); i++) if (!isdigit(s[i])) s[i] = ' ';
	stringstream inp(s);
	inp >> a >> b >> c;
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	reverse(c.begin(),c.end());
	string ans(100,'#');
	for (lena=(int)a.size(); lena<=20; lena++){
		for (lenb=(int)b.size(); lenb<=20; lenb++){
			for (lenc=(int)c.size(); lenc<=20; lenc++) if (lena+lenb+lenc+2<(int)ans.size() && lena+lenb+lenc<(int)a.size()+(int)b.size()+(int)c.size()+16){
				memset(dp,-1,sizeof dp);
				if (go(0,0,0,0,0,0)){
					A=B=C="";
					print(0,0,0,0,0,0);
					ans = A + "+" + B + "=" + C;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}