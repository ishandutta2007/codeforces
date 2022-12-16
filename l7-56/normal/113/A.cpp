#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
using namespace std;

string s;
struct dic{
	int k;
	string suf;
};
dic d[6] = {
	// /: +/- //: 1/2/3
	(dic){1, "lios"}, 
	(dic){-1, "liala"}, 
	(dic){2, "etr"}, 
	(dic){-2, "etra"}, 
	(dic){3, "initis"}, 
	(dic){-3, "inites"}, 
};

int cnt[4];
bool m;

int main(){
	cin >> s;
	int i;
	for(i = 0; i < 6; ++i)
		if(s.size() >= d[i].suf.size() && s.substr(s.size() - d[i].suf.size(), d[i].suf.size()) == d[i].suf) break;
	if(i == 6) return printf("NO"), 0;
	m = d[i].k > 0;
	cnt[abs(d[i].k)]++;
	
	while(cin >> s){
		for(i = 0; i < 6; ++i)
			if(s.size() >= d[i].suf.size() && s.substr(s.size() - d[i].suf.size(), d[i].suf.size()) == d[i].suf) break;
		if(i == 6 || m != (d[i].k > 0) || (!cnt[2] && abs(d[i].k) == 3) || (cnt[2] && abs(d[i].k) != 3) || (cnt[3] && abs(d[i].k) == 2)) return printf("NO"), 0; 
		cnt[abs(d[i].k)]++;
	}
	
	if(cnt[2] || cnt[1] + cnt[2] + cnt[3] == 1) printf("YES");
	else printf("NO");
	return 0;
}
//CF113A