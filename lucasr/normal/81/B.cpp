#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;

#define all(x) x.begin(),x.end()
#define FOR(it,x) for(__typeof(x.begin())it=x.begin();it!=x.end();++it)
#define bits(x) __builtin_popcount(x)

bool digit(char c){
	return '0'<= c && c<='9';
}

int nextInt(string s, int pos){
	int size=0;
	while (pos < s.length() && digit(s[pos])){ pos++; size++; }
	return size;
}

int nextDots(string s, int pos){
	if (s.length() < pos || !s[pos]!='.') return -1;
	
}

int nextComma(string s, int pos){
	
}

int main(){
	vector<string> terms;
	string tmp;
	while (cin>>tmp) {
		terms.push_back(tmp);
	}
	
	bool space=false;
	bool lastInt=false;
	for (int i=0;i<terms.size();i++) {
		int pos=0;
		
		while (pos<terms[i].length()){
			int next=nextInt(terms[i],pos);
			if (next>0) {
				if (!space && lastInt) cout<<" ";
				cout<<terms[i].substr(pos,next);
				space=false;
				lastInt=true;
				pos+=next;
			} else if (terms[i][pos]==',') {
				cout<<",";
				pos++;
				if (pos<terms[i].length() || i+1 < terms.size()) {
					cout<<" ";
					space=true;
				}
				lastInt=false;
			} else {
				if (space || (i==0 && pos==0)) ;
				else {
					cout<<" ";
				}
				cout<<"...";
				space=false;
				lastInt=false;
				pos+=3;
			}
		}
	}
	
	cout<<endl;
	
	return 0;
}