#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

string s,a,b;
int p,c;

int main(){
	cin >> s;
	for(p = 0; p < (int)s.size(); ++p)
		if(s[p] == '.') break;
	if(p == (int)s.size()) a = s, b = "0";
	else
		a = s.substr(0, p),
		b = s.substr(p + 1, (int)s.size() - p - 1);
	if (a == "") a = "0";
	
	c = a.size() - 1;
	a += b;
	bool flag = 1;
	for(p = 0; p < (int)a.size(); ++p)
		if(a[p] != '0') {
			flag = 0; break;
		}
	if(flag) return printf("0"), 0;
	
	p = a.size() - 1;
	while(a[p] == '0' && p > 0) p--;
	a = a.substr(0, p + 1);
	
	p = 0;
	while(a[p] == '0' && p < (int)a.size()) p++, c--;
	a = a.substr(p, (int)a.size() - p);
	
	putchar(a[0]);
	if(a.size() > 1){
		putchar('.');
		for(p = 1; p < (int)a.size(); ++p)
			putchar(a[p]);
	}
	if(c) printf("E%d", c);
		
	return 0;
}