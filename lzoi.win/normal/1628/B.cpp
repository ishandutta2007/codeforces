#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
#include<iostream>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5;
int n;
char s[MAXN][5];
int len[MAXN];
set<string> st;
bool Calc(){
	for(int i=1; i<=n; i++){
		len[i]=strlen(s[i]);
		if(len[i]==1) return 1;
		if(len[i]==2&&s[i][0]==s[i][1]) return 1;
		if(len[i]==3&&s[i][0]==s[i][2]) return 1;
	}
	st.clear();
	for(int i=1; i<=n; i++){
		string t=s[i];
		if(len[i]==2) swap(t[0],t[1]);
		else swap(t[0],t[2]);
		if(st.find(t)!=st.end()) return 1;
		if(len[i]==3){
			t.clear();
			t+=s[i][2];
			t+=s[i][1];
			if(st.find(t)!=st.end()) return 1;
		}
		st.insert(s[i]);
	}
	st.clear();
	for(int i=n; i; i--){
		string t=s[i];
		if(len[i]==2) swap(t[0],t[1]);
		else swap(t[0],t[2]);
		if(st.find(t)!=st.end()) return 1;
		if(len[i]==3){
			t.clear();
			t+=s[i][1];
			t+=s[i][0];
			if(st.find(t)!=st.end()) return 1;
		}
		st.insert(s[i]);
	}
	return 0;
}
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
			scanf("%s",s[i]);
		if(Calc()) puts("YES");
		else puts("NO");
	}
	return 0;
}