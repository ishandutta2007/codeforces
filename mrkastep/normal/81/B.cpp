#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <queue>

using namespace std;

#define ll long long int
#define For(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define mp make_pair
#define x first
#define y second

const int mod=1e9+7;
const int INF=2e9;
const ll LONGINF=4e18;

string s;
int pos;

bool num(char c){
	return (c>='0'&&c<='9');
}

string getsym(){
	string ans="";
	while(pos<(s.length())&&s[pos]==' '){
		pos++;
	}
	if(pos==s.length()) return ans;
	while(pos<s.length()&&num(s[pos])){
		ans.pb(s[pos]);
		pos++;
	}
	if(ans.length()>0) return ans;
	if(s[pos]=='.'){
		For(i,3){
			ans.pb(s[pos]);
			pos++;
		}
	}
	if(ans.length()>0) return ans;
	ans.pb(s[pos]);
	pos++;
	return ans;
}







void solve(){
	string ans="",t;
	while(pos<s.length()){
		t=getsym();
		if(t==","){
			ans+=", ";
			continue;
		}
		if(t=="..."){
			if(ans.length()!=0&&ans.back()!=' '){
				ans.pb(' ');
			}
			ans+=t;
			continue;
		}
		if(!ans.empty()&&num(ans.back())){
			ans.pb(' ');
		}
		ans+=t;
	}
	if(ans.size()>1&&ans[ans.size()-2]==','&&ans.back()==' '){
		ans.pop_back();
	}
	printf("%s\n",ans.c_str());



    
}


int main(){
#pragma comment(linker,"/STACK:268435456")
#ifdef HOME
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    int n;
    ll a;
	char c[100100];
    while(gets(c)){
		s=c;
		pos=0;
        solve();
    }




    return 0;
}