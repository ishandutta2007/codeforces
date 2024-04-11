#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const long long inf2=0x3f3f3f3f3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int n;
string s,t;
set<char> cmp;
int main(){
	cmp.insert('a');
	cmp.insert('e');
	cmp.insert('i');
	cmp.insert('o');
	cmp.insert('u');
	cin>>s>>t;
	if(s.size()!=t.size()){
		puts("NO");
		return 0;
	}
	for(int i=0;i<s.size();i++){
		if(cmp.count(s[i])!=cmp.count(t[i])){
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}